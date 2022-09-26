#include <stdio.h>

class CSet{
	
	private:
		int * mass0; //основной не изменяется
		int pow;
		
		static int tic;	
		bool Chek(int b);
		int* PushBack(const CSet& a, int m); 
		void Init(const CSet &a);
		
	public:
		
		static int Get_tic();
		int GetPow();
		CSet(int * mass0, int pow);
		CSet(int pow = 0);
		CSet(const CSet &a);
		~CSet();
		void Output() const;
		void Add (int b);
		void Del (int a);
		CSet Inter (const CSet& a);
		friend CSet Unif (const CSet& b, const CSet& a); //дружественная
		CSet Diff (const CSet& a);
		CSet SimDiff (const CSet& a);
		
		
		
};

