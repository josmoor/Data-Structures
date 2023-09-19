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
        // Position variable [0 - row, 1 - column]
        int pos[2];

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
            pos[0] = row;
            pos[1] = 1;
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
        void setColumn(int value) { pos[1] = value; }

        /**
        Type: Method
        Name: increaseCol
        Return: void
        Description:
            Increases the column value of this queen by 1.
        */
        void increaseCol(int size) {
            pos[1] += 1;
            if(pos[1] > size)
                pos[1] = 1;
        }

        /**
        Type: Method
        Name: getRow
        Return: INT
        Description:
            Gets the row that this queen is placed in.
        */
        int getRow() { return pos[0]; }

        /**
        Type: Method
        Name: getColumn
        Return: INT
        Description:
            Gets the column this queen in placed in
        */
        int getColumn() { return pos[1]; }

        /**
        Type: Method
        Name: overlap
        Parameters:
            INT - row
            INT - col
        Return: BOOLEAN
        Description:
            Checks if the current queen and the give coordinates of another queen are within direct line-of-sight
            of each other (Checking row, column, and diagonal). The rows/columns of the queens are then subtracted
            from each other and compared with their absolute value. If the value's are the same, then the digonal
            has a line-of-sight to another queen and is overlapping.
        */
        bool overlap(int row, int col) {
            int oPos[2];
            oPos[0] = row; // OTHER queen row
            oPos[1] = col; // OTHER queen col

            if(oPos[1] == pos[1]) // If Column is the same, return true
                return true;

            // Determines if the digonal has line-of-sight.
            oPos[0] = abs(oPos[0] - pos[0]);
            oPos[1] = abs(oPos[1] - pos[1]);

            if(oPos[0] == oPos[1])
                return true;

            // bool left = col > pos[1]; // Determine if OTHER queen is left or right of THIS queen
            // while(true) { // Infinite Loop
            //     if(oPos[0] == pos[0] && oPos[1] == pos[1]) // Checks if Row/Col are the same value, if so, return true.
            //         return true;
            //     else if((oPos[0] == pos[0] && oPos[1] != pos[1]) || (oPos[0] != pos[0] && oPos[1] == oPos[1])) // Checks if the Row OR Column are the same value, if so no overlap.
            //         return false;

            //     // Increase row by 1, change column based on direction (+/- 1)
            //     oPos[0] += 1;
            //     oPos[1] += left ? -1 : 1;


            //     // If the OTHER queen position hits a wall, no overlap. Return false.
            //     if(oPos[0] < 1 || oPos[0] > Vars::size || oPos[1] < 1 || oPos[1] > Vars::size)
            //         return false;
            // }

            return false;
        }
};

#endif