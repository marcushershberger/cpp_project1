// Provided by:   Marcus Hershberger
// Lab:           182
// Course number: CIS-221
// All code was typed by me.

// FILE: stats.h
// CLASS PROVIDED: Statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>
#include <cassert>

namespace main_savitch_2C
{
  class Statistician
  {
  public:
    // CONSTRUCTOR for the Statistician class:

    //  Postcondition: The object has been initialized, and is ready to accept
    //  a sequence of numbers. Various statistics will be calculated about the
    //  sequence.
    Statistician( );
    
    // Postcondition: The object has been initialized, and four arguments have been // passed to create a new instance of Statistician with existing values.
    Statistician(int count, double total, double tinyest, double largest);
    
    // MODIFICATION MEMBER FUNCTIONS

    //  The number r has been given to the Statistician as the next number in
    //  its sequence of numbers.
    void next(double r);

    //  Postcondition: The Statistician has been cleared, as if no numbers had
    //  yet been given to it.
    void reset( );

    // CONSTANT MEMBER FUNCTIONS

    //  Postcondition: The return value is the length of the sequence that has
    //  been given to the Statistician (i.e., the number of times that the
    //  next(r) function has been activated).
    int length( ) const;

    //  Postcondition: The return value is the sum of all the numbers in the
    //  Statistician's sequence.
    double sum( ) const;

    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the arithmetic mean (i.e., the
    //  average of all the numbers in the Statistician's sequence).
    double mean( ) const;
    
    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the tinyest number in the
    //  Statistician's sequence.
    double minimum( ) const;
    
    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the largest number in the
    //  Statistician's sequence.
    double maximum( ) const;
    
    // FRIEND FUNCTIONS

    //  Postcondition: The Statistician that is returned contains all the
    //  numbers of the sequences of s1 and s2.
    friend Statistician operator + (const Statistician& s1,
                                    const Statistician& s2);

    //  Postcondition: The Statistician that is returned contains the same
    //  numbers that s does, but each number has been multiplied by the
    //  scale number.
    friend Statistician operator * (double scale,
                                    const Statistician& s);

  private:
    // How many numbers in the sequence
    int count_;
    
    // The sum of all the numbers in the sequence
    double total_;

    // The smallest number in the sequence
    double tinyest_;

    // The largest number in the sequence
    double largest_;
  };

  // NON-MEMBER functions for the Statistician class

  //  Postcondition: The return value is true if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator ==(const Statistician& s1,
                   const Statistician& s2);

  //  Postcondition: The return value is false if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  not have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator !=(const Statistician& s1,
                   const Statistician& s2);
}

#endif
