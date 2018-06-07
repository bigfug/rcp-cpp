#ifndef RCP_RANGE_H
#define RCP_RANGE_H

#include <type_traits>

namespace rcp {

    template <class T,
              typename = std::enable_if<std::is_arithmetic<T>::value && !std::is_same<T, bool>::value > >
    class Range {
    public:
        Range() :
            m_value1(0)
          , m_value2(0)
        {}

        Range(T v1, T v2) :
            m_value1(v1)
          , m_value2(v2)
        {}

        void set(T v1, T v2) {
            m_value1 = v1;
            m_value2 = v2;
        }

        void setValue1(T v) {
            m_value1 = v;
        }

        void setValue2(T v) {
            m_value2 = v;
        }

        T value1() const {
            return m_value1;
        }

        T value2() const {
            return m_value2;
        }


        bool operator==(const Range<T>& other) {
            return m_value1 == other.m_value1 && m_value2 == other.m_value2;
        }

        Range& operator=(const Range& other) {
            m_value1 = other.m_value1;
            m_value2 = other.m_value2;
            return *this;
        }

    private:
        T m_value1{};
        T m_value2{};
    };

}

#endif // RCP_RANGE_H