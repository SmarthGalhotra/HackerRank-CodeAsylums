#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    long long int destinationPage = p;
    long long int totalPages = n;

    long long int flipsFromFront,flipsFromBack;
    if(destinationPage == 1) return 0;

    if(destinationPage%2 == 0) flipsFromFront = (destinationPage/2);
    else flipsFromFront = (destinationPage-1)/2;

    if(totalPages%2 == 0){ flipsFromBack= ((totalPages- (2*flipsFromFront))/2);}
    else{flipsFromBack= ((totalPages-1)-(2*flipsFromFront))/2;}

    return min(flipsFromFront,flipsFromBack);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
