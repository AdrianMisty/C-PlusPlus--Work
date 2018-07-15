//Program made by Adriana Alva
#include <fstream>
#include <algorithm>
using namespace std;

int num;				//unassigned value to this variable
string Squads[1001];//array of strings, the larger the better

int main(){

	ifstream fin("records.in");		//opening file that was given to us
	fin >> num;				//reading data from file is provided starting from here till the
                                                                   //    end of the code
	for (int k=0; k<num; k++)
{
	string BeingSorted[3];			//we are using a string array since the data contents “records”

	fin >> BeingSorted[0] >> BeingSorted[1] >> BeingSorted[2];
                                                                // data in file is being placed in Beingstored array
	sort(BeingSorted,BeingSorted+3);      //sorting occurs here before we convert the entire line into string
Squads[k]=BeingSorted[0]+" "+BeingSorted[1]+" "+BeingSorted[2];
                                                                 // Because of how the data is being read, the names of the cows will be combined together, so in order to have their names separated individually we will add spaces in between them and the array is 3 since grous of 3 cows get recorded by the Farmer


//*sidenote:there is only 0-1-2 and not a three because of how array’s are read.Array’s start with a zero and then so on and so forth.
}
	fin.close();//end any changed to num and the array that was established
	int AccurateCounting=0;
	for (int k=0; k<num; k++){
	int GenericCounting=0;                          // search for the groups that are same as initial group that was
     for (int x=0; x<num; x++)                       //   sorted,squad[k]
		if (Squads[k]==Squads[x])
                              GenericCounting++;//update generic counting variable if there is the
                                                                  //    same cow group
	               if (GenericCounting>AccurateCounting) // and if statement that is always true
                     AccurateCounting=GenericCounting;// update the accurate counting variable in order to come up with a full total counting
	}//end of loop
	ofstream fout("records.out");//closing the file		//making sure the file is ended, this isn't necessary though so it can be ignored
	fout << AccurateCounting << endl;//print out the total to display the desired format
	fout.close();//the end
}
