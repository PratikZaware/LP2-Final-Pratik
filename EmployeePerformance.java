import java.util.ArrayList;
import java.util.Scanner;

public class EmployeePerformance {

	public static void main(String[] args) 
	{
		Scanner sc=new Scanner(System.in);
		String name;
		System.out.println("Employee name : ");
		name=sc.next();
		int age;
		age=sc.nextInt();
		int duration;
		duration=sc.nextInt(); 
		
		ArrayList<String>questions=new ArrayList<>();
		questions.add("How is the performance of employee? Rate from 1 to 5");
		questions.add("How is the behaviour of employee? Rate from 1 to 5");
		questions.add("How good is the employee in develoment? Rate from 1 to 5");
		questions.add("How good is the employee in technical skills? Rate from 1 to 5");
		questions.add("How does the employee work in team? Rate from 1 to 5");
		questions.add("Based on regularity rate from 1 to 5");
		questions.add("Based on timely submission rate from 1 to 5");
		
		
		int arr[]=new int[4];
		
//		0 excellent
//		1 good
//		2 average
//		3 poor
		
		int score;
		
		for(int i=0;i<questions.size();i++)
		{
			System.out.println(questions.get(i));
			score=sc.nextInt();
			if(score<=2)
			{
				arr[3]++;
			}
			else if(score==3)
			{
				arr[2]++;
			}
			else if(score==4)
			{
				arr[1]++;
			}
			else
			{
				arr[0]++;
			}
		}
		
		int maxind=0;
		int max=arr[0];
		for(int i=1;i<4;i++)
		{
			if(arr[i]>max)
			{
				maxind=i;
				max=arr[i];
			}
		}
		
		if(maxind==0)
		{
			System.out.println(name+" is excellent employee!");
		}
		else if(maxind==1)
		{
			System.out.println(name+" is good employee!");
		}
		else if(maxind==2)
		{
			System.out.println(name+" is average employee!");
		}
		else
		{
			System.out.println(name+" is poor employee!");
		}
	}

}