//
// Created by MrChi on 18.09.2022.
//

#ifndef OPUS_MAGNUM_TSCHOWEK_HPP
#define OPUS_MAGNUM_TSCHOWEK_HPP

template<typename T>
class TSchowek
{
public:
    void schowaj(T x)
    {
        sejf = x;
    }

    T oddaj()
    {
        return sejf;
    }

private:
    T sejf;
};


#endif //OPUS_MAGNUM_TSCHOWEK_HPP
