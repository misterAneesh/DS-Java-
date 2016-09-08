import java.util.Stack;
class Stac
{

	public static void main(String[] args) {
		Stack stack = new Stack();
		int num = 5;
		while(num!=0)
		{
			stack.push(num);
			num--;
		}
		num = 5;
		while(num!=0)
		{
			System.out.println(stack.pop());
			num--;
		}
	}
}