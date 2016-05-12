class ListM{
	public int[] l;
	public int search;
	public boolean found;
}
public class SearchOneMillionInts {
	public static void main(String[] args)
	{
		ListM lm;
		
		lm = new ListM();
		lm.l = new int[1000000];
		SearchOneMillionInts.populate(lm.l);
		if(SearchOneMillionInts.searchfor2(lm.l)){
			lm.found = true;
		}
		else{
			lm.found = false;
		}
		
	}
	
	static boolean searchfor2(int[] list){
		int i;
		ListM lm;
		
		i=0;
		lm = new ListM();
		lm.search = 2;
		while(i<1000000){
			if(list[i]== lm.search){
				return true;
			}
			i++;
		}
		return false;
	}
	
	static void populate(int[] list)
	{
		int i;
		for(i=0;i<1000000;i++)
		{
			list[i] = i;
		}
	}

}
