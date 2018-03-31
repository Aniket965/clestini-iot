#include <iostream>
#include <vector>

using namespace std;

int main() {
    int i,j,n,m;
    cin>>n>>m; //n=row; m=column
    //we can use a loop for taking input from the user
    vector <vector<int>> matrix;
    for(i=0; i<n; ++i){
        vector<int>row;
        for(j=0; j<m; ++j){
            int value;
            cin>>value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    int search_value;
    //Enter the search value;
    cin>>search_value;
    int size = matrix.size();
    bool found = false;
	i = 0;
	j = size - 1;
    while ( i < size && j >= 0 )
    {
        if ( matrix[i][j] == search_value )
            {
                cout<<"\n Element Found at " << i << ", " << j;
                found = true;
                //found
                break;
            }
        if ( matrix[i][j] > search_value )
               j--;
        else //   matrix[i][j] < search_value
              i++;
    }
    if(!found)
        cout<<"\n Element not found";
	return 0;
}

//COMPLEXITY (TIME) IS O(M+N)