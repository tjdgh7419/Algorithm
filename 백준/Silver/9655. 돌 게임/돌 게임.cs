public class Program
	{
		static void Main(string[] args)
		{
			string N = Console.ReadLine();
			
			if(int.Parse(N) % 2 == 0)
			{
                Console.WriteLine("CY");
            }
			else
			{
                Console.WriteLine("SK");
            }
        }
	}