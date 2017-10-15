// Provided by:   Marcus Hershberger
// Lab:           182
// Course number: CIS-221
// All code was typed by me; collaboration was done by Jonah Atkinson, Chris Myers, and Tyler Snodderly.

// FILE: stats.h
// CLASS PROVIDED: Statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace main_savitch_2C.
//
// VALUE SEMANTICS for the Statistician class:
// Assignments and the copy constructor may be used with Statistician objects.

#include "stats.h"
 
namespace main_savitch_2C
{
  //  Postcondition: The object has been initialized, and is ready to accept
  //  a sequence of numbers. Various statistics will be calculated about the
  //  sequence.
  Statistician::Statistician( )
  {
      count_ = 0;
      total_ = 0.0;
      tinyest_ = 0.0;
      largest_ = 0.0;
  }
    
    
  Statistician::Statistician(int count, double total, double tinyest, double largest)
  {
      count_ = count;
      total_ = total;
      tinyest_ = tinyest;
      largest_ = largest;
  }

  //  The number r has been given to the Statistician as the next number in
  //  its sequence of numbers.
  void Statistician::next(double r)
  {
      count_ += 1;
      total_ += r;
      if (length() == 1)
      {
          tinyest_ = r;
          largest_ = r;
      }
      else
      {
        if (r < minimum())
        {
            tinyest_ = r;
        }
        if (r > maximum())
        {
            largest_ = r;
        }
      }
  }

  //  Postcondition: The Statistician has been cleared, as if no numbers had
  //  yet been given to it.
  void Statistician::reset( )
  {
      count_ = 0;
      total_ = 0.0;
      tinyest_ = 0.0;
      largest_ = 0.0;
  }
  //  Postcondition: The return value is the length of the sequence that has
  //  been given to the Statistician (i.e., the number of times that the
  //  next(r) function has been activated).
  int Statistician::length( ) const
  {
    return count_;
  }

  //  Postcondition: The return value is the sum of all the numbers in the
  //  Statistician's sequence.
  double Statistician::sum( ) const
  {
    return total_;
  }

  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the arithmetic mean (i.e., the
  //  average of all the numbers in the Statistician's sequence).
  double Statistician::mean( ) const
  {
    assert(length() > 0);
    if (length() > 0)
    {
        return (total_ / count_);
    }
    else
    {
        return 0.0;
    }
  }
    
  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the tinyest number in the
  //  Statistician's sequence.
  double Statistician::minimum( ) const
  {
    return tinyest_;
  }
    
  //  Precondition: length( ) > 0
  //  Postcondition: The return value is the largest number in the
  //  Statistician's sequence.
  double Statistician::maximum( ) const
  {
    return largest_;
  }
    
  //  Postcondition: The Statistician that is returned contains all the
  //  numbers of the sequences of s1 and s2.
  Statistician operator + (const Statistician& s1,
			   const Statistician& s2)
  {
      
      int combined_count_;
      double combined_total_, compared_min_, compared_max_;
      
      combined_count_ = s1.length() + s2.length();
      combined_total_ = s1.sum() + s2.sum();
      
      if ((s1.minimum() < s2.minimum() || s1.minimum() == s2.minimum() || s2.length() == 0) && s1.length() > 0)
      {
          compared_min_ = s1.minimum();
      }
      else if (s2.length() > 0)
      {
          compared_min_ = s2.minimum(); 
      }
      else 
      {
          compared_min_ = 0.0;
      }
      
      
      if ((s1.maximum() > s2.maximum() || s1.maximum() == s2.maximum() || s2.length() ==0) && s1.length() > 0)
      {
          compared_max_ = s1.maximum();
      }
      else if (s2.length() > 0)
      {
          compared_max_ = s2.maximum();
      }
      else 
      {
          compared_max_ = 0.0;
      }
      
      
      Statistician statsum(combined_count_, combined_total_, compared_min_, compared_max_);
      
      return statsum;
  }

  //  Postcondition: The Statistician that is returned contains the same
  //  numbers that s does, but each number has been multiplied by the
  //  scale number.
  Statistician operator * (double scale,
			   const Statistician& s)
  {
      double mult_total_, mult_min_, mult_max_;
      mult_total_ = scale * s.sum();
      if (scale >= 0)
      {
          mult_min_ = scale * s.minimum();
          mult_max_ = scale * s.maximum();
      }
      else
      {
          mult_min_ = scale * s.maximum();
          mult_max_ = scale * s.minimum();
      }
      Statistician scalestat(s.length(), mult_total_, mult_min_, mult_max_);
      return scalestat;
  }

  //  Postcondition: The return value is true if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator ==(const Statistician& s1,
                   const Statistician& s2)
  {
      return ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()));
  }

  //  Postcondition: The return value is false if s1 and s2 have zero
  //  length. Also, if the length is greater than zero, then s1 and s2 must
  //  not have the same length, the same  mean, the same minimum, 
  //  the same maximum, and the same sum.
  bool operator !=(const Statistician& s1,
                   const Statistician& s2)
  {
    return !((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()));
  }
}
