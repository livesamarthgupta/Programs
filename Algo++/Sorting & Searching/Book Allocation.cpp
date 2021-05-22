#include<bits/stdc++.h>
using namespace std;

bool isPossible(long books[], long noBooks, long stud, long curr_min) {
	long noOfStud = 1;
	long pagesRead = 0;
	
	for(long i = 0; i < noBooks; i++) {
		if(pagesRead + books[i] > curr_min) {
			noOfStud++;
			pagesRead = books[i];
			if(noOfStud > stud)
				return false;
		} else {
			pagesRead += books[i];
		}
	}
	
	return true;
}


long find_min_pages(long books[], long noBooks, long stud) {
	long totalPages = 0;
	for(long i = 0; i < noBooks; i++)	
		totalPages += books[i];
		
		
	long s = books[0];
	long e = totalPages;
	long ans = LONG_MAX;
	
	while(s <= e){
		long mid = (s + e) / 2;
		if(isPossible(books, noBooks, stud, mid)) {
			ans = mid;
			e = mid - 1;
		} else
			s = mid + 1;
	}
	
	return ans;
}


int main() {
	long t;
	cin>>t;
	while(t--) {
		long no_of_books, stud;
		cin>>no_of_books>>stud;
		
		long book[no_of_books];
		for(long i = 0; i < no_of_books; i++)
			cin>>book[i];
			
		cout<<find_min_pages(book, no_of_books, stud)<<endl;
	}
	
	
	
	return 0;
}
