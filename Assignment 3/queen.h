#ifndef QUEEN_H
#define QUEEN_H
#include <math.h>

/**
Type: Class
Name: Queen
Desscription:
    A class object containing the location of the Queen on the board.
*/
class Queen {
    private:
        // Position (Row [r] | Column [c])
        int r;
        int c;

    public:
        // Generic Constructor
        Queen() { }

        /**
        Type: Constructor
        Parameters: INT - row
        Description:
            Initializes a new Queen object with setting the
            value of the row of the queen. All queens start
            at the first column.
        */
        Queen(int row) {
            r = row;
            c = 1;
        }

        /**
        Type: Deconstructor
        Description: Used with in-tangent with Vectors/Stacks to ensure memory is released on popping.
        */
        ~Queen() { }

        /**
        Type: Method
        Name: setColumn
        Parameters: INT - value
        Return: void
        Description:
            Sets the column of the queen.
        */
        void setColumn(int value) {
            c = value;
        }

        /**
        Type: Method
        Name: increaseCol
        Return: void
        Description:
            Increases the column value of this queen by 1.
        */
        void increaseCol() {
            c++;
        }

        /**
        Type: Method
        Name: getRow
        Return: INT
        Description:
            Gets the row that this queen is placed in.
        */
        int getRow() {
            return r;
        }

        /**
        Type: Method
        Name: getColumn
        Return: INT
        Description:
            Gets the column this queen in placed in
        */
        int getColumn() {
            return c;
        }

        /**
        Type: Method
        Name: overlap
        Parameters:
            INT - row
            INT - col
        Return: BOOLEAN
        Description:
            Checks if the current queen and the give coordinates of another queen are within direct line-of-sight
            of each other (Checking column and diagonal). The rows/columns of the queens are then subtracted
            from each other and compared with their absolute value. If the value's are the same, then the digonal
            has a line-of-sight to another queen and is overlapping.
        */
        bool overlap(int row, int col) {
            int oPos[2];
            oPos[0] = row; // OTHER queen row
            oPos[1] = col; // OTHER queen col

            if(oPos[1] == c) // If Column is the same, return true
                return true;

            // Determines if the digonal has line-of-sight.
            oPos[0] = abs(oPos[0] - r);
            oPos[1] = abs(oPos[1] - c);

            if(oPos[0] == oPos[1])
                return true;

            return false;
        }
};

#endif