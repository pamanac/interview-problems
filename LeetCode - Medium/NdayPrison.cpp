//
// There are 8 prison cells in a row and each cell is either occupied or vacant.
//
//Each day, whether the cell is occupied or vacant changes according to the following rules:
//
//If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
//Otherwise, it becomes vacant.
//Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//
//You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//
//Return the state of the prison after n days (i.e., n such changes described above).
//

class Solution {
    void nextGen(vector<int>& cells){
        const int N = cells.size();
        vector<int> changes;
        if(cells[0] == 1)
            changes.push_back(0);
        if(cells[N-1] == 1)
            changes.push_back(N-1);
        for(int i = 1; i < N-1; i++){
            bool bothOccupied = cells[i-1] == 1 and cells[i+1] == 1 ? true:false;
            bool bothVacant = cells[i-1] == 0 and cells[i+1] == 0 ? true:false;
            if(bothOccupied || bothVacant){
                if(cells[i] == 0){
                    changes.push_back(i);
                }
            }else{
                if(cells[i] == 1){
                    changes.push_back(i);
                }
            }
        }
        for(auto index : changes){
            cells[index] = cells[index] == 0 ? 1 : 0;
        }
    }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        nextGen(cells);
        vector<int> initial = cells;
        bool checkLoop = true;
        for(int day = 1; day < n; day++){
            nextGen(cells);
            if(checkLoop and day > 2 and day < 2*cells.size()){
                if(std::equal(initial.begin(), initial.end(), cells.begin())){
                    n = n%day;
                    checkLoop = false;
                    day = 0;
                }
            }
        }
        return cells;
    }
};
