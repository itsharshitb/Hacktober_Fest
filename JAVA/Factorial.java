class Factorial
{
	public static void main(String args[])
	{
		int n=5,i;
		long fact=1;
		//input n
		for (i=1;i<=n;i++)
			fact*=i;
		System.out.println("Factorial of "+n+" is = "+ fact);

	}
}