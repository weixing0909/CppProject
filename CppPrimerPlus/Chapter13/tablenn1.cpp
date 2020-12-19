#include <iostream>
#include "tablenn1.h"

TableTennisPlayer::TableTennisPlayer(const string & fn,
                      const string & ln, bool ht) :
                      firstname(fn),
                      lastname(ln),
                      hasTable(ht) {}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
    const string & ln, bool ht)
    : rating(r), TableTennisPlayer(fn, ln, ht) {}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
    : rating(r), TableTennisPlayer(tp)
{

}