// --> YOUR NAME here
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
// ADDING A NEW COMMENT
namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points2D()
    {
        sequence_= nullptr;
        size_ = 0;
    }

    // Copy-constructor.
    Points2D(const Points2D &rhs)
    {
        // sequence_ = new std::array<Object,2>[rhs.size()];
        // sequence_ = rhs.sequence_;
        // size_ = rhs.size();
        size_ = rhs.size_;
        sequence_ = new std::array<Object,2>[size_];

        for(int i = 0; i < size_;i++)
        {
            sequence_[i][0] = rhs.sequence_[i][0];
            sequence_[i][1] = rhs.sequence_[i][1];
        }
    }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points2D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points2D& operator=(const Points2D &rhs)
    {
        Points2D copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // Move-constructor.
    Points2D(Points2D &&rhs)
    {
        size_ = rhs.size_;
        sequence_ = new std::array<Object,2>[size_];

        for(int i = 0; i < size_;i++)
        {
            sequence_[i][0] = rhs.sequence_[i][0];
            sequence_[i][1] = rhs.sequence_[i][1];
        }
       // sequence_ = rhs.sequence_;

        rhs.size_ = 0;
        rhs.sequence_ = nullptr;
        //rhs.sequence_ = [];
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs)
    {
         std::swap(size_, rhs.size_);
         std::swap(sequence_, rhs.sequence_);
         return *this;
    }

    ~Points2D()
    {
        delete[] sequence_;
        size_ = 0;
    }

    // End of big-five.

    // One parameter constructor.
    Points2D(const std::array<Object, 2>& item) {
        //size_ = sizeof(item)/item[0];
        size_ = item.size();
        sequence_= new std::array<Object,2>[size_];

       //sequence_ = *item;
        // Provide code.

        for(int i = 0; i < item.size();i++)
        {
           // *(sequence_)[0] = item[i];
           // *(sequence_+i)[1] = item[i];
           sequence_[i][0] = item[i];
            sequence_[i][1] = item[i];
        }
            
    }

    size_t size() const {
        return size_;
        // Code missing.
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const {

        if(location >= 0 && location < size_)
        {
            //std::array<Object,2> result = new array<Object,2>[2];
            
            //return sequence_[location][0];
            //return result;
            return *(sequence_ + location);
        }
        else
        {
           // std:: cout << "aborted operator[]";
        
            abort();
        }
         
        // Code missing.
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        // Code missing.
        //return 1;
        Points2D result;
        bool secondLarger = (c2.size() >= c1.size());

        if(secondLarger)
            {
                result = c2;
               // std::cout << "result is : " << result;
                for(int i = 0; i < c1.size_; i++)
                {
                    
                    result.sequence_[i][0]+= c1.sequence_[i][0];
                    result.sequence_[i][1]+= c1.sequence_[i][1];
                   // std:: cout << "sum is: " << result.sequence_[i][0] << " " << result.sequence_[i][1] << "\n";
                }
            }
        else{
                result = c1;
               // std::cout << "result is : " << result;
                for(int i = 0; i < c2.size_;i++)
                {
                    result.sequence_[i][0]+= c1.sequence_[i][0];
                    result.sequence_[i][1]+= c1.sequence_[i][1];
                   // std:: cout << "sum is: " << result.sequence_[i][0] << " " << result.sequence_[i][1] << "\n";
                }
            }
        
        return result;
    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        for(int i = 0; i < some_points.size();i++)
             out << "(" <<some_points[i][0] << "," << some_points[i][1] << ") ";
        // Code missing.
        std::cout << "\n";
        return out;
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        //the 1st number we take in, so if it's 3, that means we have 3 points (each points has 2 nums)
        int totalPoints = 0;
        in >> totalPoints;

        some_points.size_ = totalPoints;
        some_points.sequence_ = new std::array<Object,2>[totalPoints];

        //don't know if it's int or double so I used Object as a "placeholder". 
        Object entry1;
        Object entry2;

        //for each point takes in the 1st and 2nd number and inserts them into the array.
        for(int i = 0; i < totalPoints;i++)
        {
            in >> entry1;
            some_points.sequence_[i][0] = entry1;
            in >> entry2;
            some_points.sequence_[i][1] = entry2;

        }
        return in;
        // Code missing.
    }

  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

} // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_