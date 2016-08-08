﻿#ifndef KHUTILS_DATAMWRITER_HPP_INC
#define KHUTILS_DATAMWRITER_HPP_INC

//! file has dependency on boost.endian
//! include wisely to keep compile times minimal

#include "khutils/typeconversion.hpp"

#include <boost/endian/conversion.hpp>
#include <functional>

namespace khutils
{
	using boost::endian::order;

	//! data writer
	//! writes data into PRE-ALLOCATED buffer
	//! DOES NOT RESIZE BUFFER
	//! usage: use typedef'ed version (see below)
	template <typename ByteForwardIterator, order _order>
	struct _datawriter;

	template <typename ByteForwardIterator>
	using datawriter = _datawriter<ByteForwardIterator, order::native>;
	template <typename ByteForwardIterator>
	using little_endian_datawriter = _datawriter<ByteForwardIterator, order::little>;
	template <typename ByteForwardIterator>
	using big_endian_datawriter = _datawriter<ByteForwardIterator, order::big>;

	template <typename ByteForwardIterator, order _order>
	struct _datawriter
	{
		ByteForwardIterator m_begin;
		ByteForwardIterator m_end;
		ByteForwardIterator m_current;

		_datawriter()					= delete;
		_datawriter(const _datawriter&) = default;
		_datawriter(_datawriter&&)		= default;
		_datawriter(ByteForwardIterator begin, ByteForwardIterator end)
			: m_begin(begin)	//
			, m_end(end)
			, m_current(m_begin)
		{
		}

		_datawriter& operator=(const _datawriter&) = default;
		_datawriter& operator=(_datawriter&&) = default;

		//! writes _WriteT into buffer after converting and endian-swapping provided
		//! _InT
		//! optional convert function can be used to downsample _InT into bytewise
		//! smaller _WriteT
		//! e.g. to write F32 as U16
		template <typename _WriteT, typename _InT = _WriteT>
		void write(_InT t, std::function<_WriteT(_InT)> convert = std::bind(reinterpret_convert<_WriteT, _InT>, std::placeholders::_1))
		{
			using boost::endian::conditional_reverse;

			_WriteT r = conditional_reverse<_order, order::native>(convert(t));

			char* rawdata = reinterpret_cast<char*>(&r);
			for (size_t i = 0; i < sizeof(_WriteT); ++i)
			{
				if (m_current != m_end)
				{
					*(m_current) = rawdata[i];
				}
				++m_current;
			}
		}

		template <typename _SkipT>
		void skip(size_t count = 1)
		{
			m_current += (sizeof(_SkipT) * count);
		}

		template <size_t _Alignment>
		void			 alignToNext()
		{
			auto pos			= std::distance(m_begin, m_current);
			auto nextAlignedPos = ((pos / _Alignment) + 1) * _Alignment;
			m_current			= m_begin + (nextAlignedPos - pos);
		}
	};

}	// namespace khutils

#endif	// KHUTILS_DATAMWRITER_HPP_INC
