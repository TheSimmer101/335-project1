Modified provided points2d.h file\
Author: Rachel Briskman\
Course: CSCI-33500\
Instructor: Jaime Canizales\
Assignment: 1

Summer 2024

For testing I ran the code both locally on my computer (WSL Ubuntu on Windows 10) and with the given Dockerfile.
THe output matched on both and I was able to use Docker successfully.

For the operator+(), where we add the points, I made a copy of the Point with the larger sequence (using the copy assignment operator= for convenience), and then I added the shorter sequence to that copy, instead of adding both willy nilly and then worrying about appending the rest if the lengths don't match.
For example:\
 (A,B) (C,D) (E,F)\
 (W,X) (Y,Z)

Result = (A+W, B+X) (C+Y, D+Z) (E+F)

Length of Result sequence = length of the longer parameter sequence

If we add those 2 sequences, the function stores a copy of the top sequence, then it adds the other one (making sure the indices line up when adding). I did it this way because it's less work than storing index 2 (which is where we would start to append the remainder (E,F). This prevents us from doing another loop, since it would have to go index 2 until the end of the longer sequence.

I made a bool called secondLarger, which compares the parameter sequence lengths. Inside the conditional, the code is pretty much the same, except I switched the positions of c1 and c2 inside the if (when actually doing the addition).
The resulting sequence after adding is stored inside a new Point2d object, called result, which is returned.


This comment felt too wordy to put inside the actual header file, so I wrote this here


Some of my other functions have several lines commented out, and those are not necessary anymore. I was trying different approaches while figuring out how to deal with the sequence_, the pointer to array stuff. Those lines can be ignored.

The rest of my comments explaining my solution to the code are in the header file, and on the top there is a summary of what I modified.
