public class testing
{	
	public int factorial(int number)
		{
			if (number  == 0)
			{
				return 1;
			}
			int ret_val = number * factorial(number-1);
			return ret_val;
		}
	public int convert_str(String str)
		{
			return (Integer.parseInt(str));
		}

	public static void main(String []args)
		{
			testing number = new testing();

			int c_number = number.convert_str(args[0]);
			int f_number = number.factorial(c_number);
			
			System.out.println("The factorial of number " + args[0] + " : " + f_number);
		}
}
