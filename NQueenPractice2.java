import java.util.*;

public class NQueenPractice2
{
	public static void main(String[] args) 
	{
		int n=5;
		int board[][]=new int[n][n];

		// solveUsingBacktracking(board,0,n,new ArrayList());	

		int column[]=new int[n];
		int diag[]=new int[2*n-1];
		int rdiag[]=new int[2*n-1];

		solveUsingBranchandBound(board,0,n,new ArrayList(),column,diag,rdiag);
	}

	public static void solveUsingBacktracking(int board[][],int row,int n,ArrayList<String>ls)
	{
		if(row==n)
		{
			System.out.println(ls);
			return;
		}

		for(int i=0;i<n;i++)
		{
			if(isSafe(row,i,board,n))
			{
				int col=i;
				board[row][col]=1;
				String pos=String.valueOf(row)+" "+String.valueOf(col);
				ls.add(pos);

				solveUsingBacktracking(board,row+1,n,ls);

				board[row][col]=0;
				ls.remove(ls.size()-1);
			}
		}
	}

	public static boolean isSafe(int row,int col,int board[][],int n)
	{
		for(int i=0;i<n;i++)
		{
			if(board[i][col]==1)
			{
				return false;
			}
		}

		int row1=row;
		int col1=col;

		while(row1>=0 && col1>=0)
		{
			if(board[row1][col1]==1)
			{
				return false;
			}
			row1--;
			col1--;
		}

		row1=row;
		col1=col;

		while(row1>=0 && col1<n)
		{
			if(board[row1][col1]==1)
			{
				return false;
			}
			row1--;
			col1++;
		}

		return true;
	}

	public static void solveUsingBranchandBound(int board[][],int row,int n,ArrayList<String>ls,int column[],int diag[],int rdiag[])
	{
		if(row==n)
		{
			System.out.println(ls);
			return;
		}

		for(int i=0;i<n;i++)
		{
			int col=i;
			if(column[i]==0 && diag[row+col]==0 && rdiag[row-col+n-1]==0)
			{
				column[i]=1;
				diag[row+col]=1;
				rdiag[row-col+n-1]=1;
				board[row][col]=1;
				String pos=String.valueOf(row)+" "+String.valueOf(col);
				ls.add(pos);

				solveUsingBranchandBound(board,row+1,n,ls,column,diag,rdiag);

				column[i]=0;
				diag[row+col]=0;
				rdiag[row-col+n-1]=0;
				board[row][col]=0;
				ls.remove(ls.size()-1);
			}
		}
	}
}