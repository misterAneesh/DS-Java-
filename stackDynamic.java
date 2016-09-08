	import java.util.*;
	class Stack1
	{
			private int top = -1; // dont want client to access them
			private int size = 0;
			private int [] a = new int[1];
			private int capacity = 1000;
		private int[] grow(int size1)
		{
			int a1[] = Arrays.copyOf(a,a.length * 2);
			int i;
			return a1;
		}
		private int[] shrink(int size1)
		{
			int a1[] = Arrays.copyOf(a,a.length * (1/2));
			return a1;
		}
		public void Push(int d)
		{
			if(size>=capacity)
				{
					return;
				}	
			if(size == a.length)
			{
				a = grow(size);
			}	
				
			top++;
			size++;
			a[top] = d;
		}
		public int pop()
		{
			if(size==0)
			{
				System.out.println("StackEmpty\n");
				return -1;	
			}

			if(top <= ((a.length)/4)) // length returns allocated memory...here .. i.e 4 times top  = length
			{
				a  = shrink(size);
			}

			top--;
			size--;
			return a[top + 1];
		}
		public void printStack()
		{
			for (int i = 0; i < size ; i++ ) 
			{
				System.out.println(a[i] + " ");
			}
		}
		public static void main(String[] args) 
		{
			Stack1 obj = new Stack1();
			obj.Push(1);
			obj.Push(2);
			obj.Push(3);
			System.out.println(obj.pop());
			obj.printStack();
		}

	}
	
