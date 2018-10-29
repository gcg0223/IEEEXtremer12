import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		//PriorityQueue<Integer> queue=new PriorityQueue<>();
		LinkedList<Integer> list=new LinkedList<>();
		for(int i=0;i<n;i++){
			int num=sc.nextInt();
			list.add(num);
		}
		Collections.sort(list);
		ArrayList<Integer> validList=new ArrayList<>(n);
		ArrayList<Integer> twices=new ArrayList<>();
		validList.add(list.get(0)-1);
		for(int i=1;i<n;i++){
			if(list.get(i)-list.get(i-1)>1){
				for(int j=list.get(i-1)+1;j<list.get(i);j++)
					validList.add(j);
			}
			else if(list.get(i)-list.get(i-1)==0)
				twices.add(list.get(i));
		}
		validList.add(list.getLast()+1);
		int sum=0;
		for(Integer num:twices){
				int index=findMinNum(num,validList);
				sum+=Math.abs(num-validList.get(index));
				if (index==0) 
					validList.set(0, validList.get(0)-1);
				else if(index==validList.size()-1)
					validList.set(validList.size()-1, validList.get(validList.size()-1)+1);
				else
					validList.remove(index);	
		}
		System.out.println(sum);
	}
	
	public static int findMinNum(int num,ArrayList<Integer> validList){
		if(validList.get(0)>num)
			return 0;
		if(validList.get(validList.size()-1)<num)
			return validList.size()-1;
		int minIndex=0;
		int minDis=Math.abs(validList.get(0)-num);
		for(int i=1;i<validList.size();i++){
			if(Math.abs(validList.get(i)-num)<minDis){
				minDis=Math.abs(validList.get(i)-num);
				minIndex=i;
			}
				
		}
		int a = 0;
		return minIndex;
	}
}
