	class Stack
	{
		
			int top = -1;
			int size = 0;
			int [] a = new int[1000];
			int capacity = 1000;
		
		void Push(int d)
		{
			if(size>=capacity)
				{
					System.out.println("StackFull\n");
					return;
				}	
				
			top++;
			size++;
			a[top] = d;
		}
		int pop()
		{
			if(size==0)
			{
				System.out.println("StackEmpty\n");
				return -1;	
			};
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
			Stack obj = new Stack();
			obj.Push(1);
			obj.Push(2);
			obj.Push(3);
			System.out.println(obj.pop());
			obj.printStack();
		}

	}
	
