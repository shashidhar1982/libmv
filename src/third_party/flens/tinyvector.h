/*
 *   Copyright (c) 2007, Michael Lehn
 *
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1) Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *   2) Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in
 *      the documentation and/or other materials provided with the
 *      distribution.
 *   3) Neither the name of the FLENS development group nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FLENS_TINYVECTOR_H
#define FLENS_TINYVECTOR_H 1

#include <flens/matvec.h>
#include <flens/listinitializer.h>
#include <flens/fixedsizearray.h>

namespace flens {

// == TinyVector ==============================================================

template <typename A>
class TinyVector
    : public Vector<TinyVector<A> >
{
    public:
        typedef typename TypeInfo<TinyVector<A> >::ElementType T;        
        
        TinyVector();

        // -- operators --------------------------------------------------------

        ListInitializer<A>
        operator=(const T &value);

        TinyVector<A> &
        operator=(const TinyVector<A> &rhs);

        template <typename RHS>
            TinyVector<A> &
            operator=(const Vector<RHS> &rhs);

        template <typename RHS>
            TinyVector<A> &
            operator+=(const Vector<RHS> &rhs);

        template <typename RHS>
            TinyVector<A> &
            operator-=(const Vector<RHS> &rhs);

        TinyVector<A> &
        operator*=(T alpha);

        TinyVector<A> &
        operator/=(T alpha);

        const T &
        operator()(int index) const;

        T &
        operator()(int index);

        //-- methods -----------------------------------------------------------

        int
        length() const;

        int
        firstIndex() const;

        int
        lastIndex() const;

        int
        stride() const;
        
        void
        resize(int length);

        void
        resize(int length, int firstIndex);

        const T *
        data() const;

        T *
        data();

        const A &
        engine() const;

        A &
        engine();

    private:
        A _engine;
};

template <typename A>
struct TypeInfo<TinyVector<A> >
{
    typedef TinyVector<A> Impl;
    typedef typename A::ElementType ElementType;
};

} // namespace flens

#include <flens/tinyvector.tcc>

#endif // FLENS_TINYVECTOR_H
