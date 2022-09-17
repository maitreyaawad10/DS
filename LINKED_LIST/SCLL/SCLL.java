import java.util.Scanner;

class node
{
    public int data;
    public node next;
}

class SinglyCLL
{
    private node Head;
    private node Tail;
    private int Count;

    public SinglyCLL()      // Constructor
    {
        Head = null;
        Tail = null;
        Count = 0;
    }

    public void InsertFirst(int value)  
    {
        node newn = new node();

        newn.data = value;
        newn.next = null;

        if(Head == null && Tail == null)        // If LL is empty
        {
            Head = newn;
            Tail = newn;
        }

        else        // If LL contains atleast 1 element
        {   
            newn.next = Head;
            Head = newn;
        }

        Tail.next = Head;
        Count++;
    }

    public void InsertLast(int value)
    {
        node newn = new node();

        newn.data = value;
        newn.next = null;

        if(Head == null && Tail == null)        // If LL is empty
        {
            Head = newn;
            Tail = newn;
        }

        else        // If LL contains atleast 1 element
        {
            Tail.next = newn;
            Tail = newn;
        }

        Tail.next = Head;
        Count++;
    }

    public void DeleteFirst()
    {
        if(Head == null && Tail == null)        // If LL is empty
        {
            return;
        }

        else if(Head == Tail)        // If LL contains only 1 element
        {
            Head = null;
            Tail = null;
        }

        else            // If LL contains more than 1 element
        {
            Head = Head.next;
            Tail.next = Head;
        }

        Count--;
    }

    public void DeleteLast()
    {
        if(Head == null && Tail == null)        // If LL is empty
        {
            return;
        }

        else if(Head == Tail)        // If LL contains only 1 element
        {
            Head = null;
            Tail = null;
        }

        else            // If LL contains more than 1 element
        {
            node temp = Head;

            while(temp.next != Tail)
            {
                temp = temp.next;
            }

            temp.next = null;
            Tail = temp;
            Tail.next = Head;
        }

        Count--;
    }

    public void InsertAtPos(int value, int pos)
    {
        if(pos < 1 || pos > Count+1)
        {
            System.out.println("Invalid position!\n");
            return;
        }

        if(pos == 1)        // InsertFirst
        {
            InsertFirst(value);
        }

        else if(pos == Count+1)     // InsertLast
        {
            InsertLast(value);
        }

        else        // Inserting at any random position
        {
            node newn = new node();

            newn.data = value;
            newn.next = null;
            
            node temp = Head;

            for(int i = 1; i < pos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            Count++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > Count)
        {
            System.out.println("Invalid position!\n");
            return;
        }

        if(pos == 1)        // DeleteFirst
        {
            DeleteFirst();
        }

        else if(pos == Count)       // DeleteLast
        {
            DeleteLast();
        }

        else        // Deleting at any random position
        {
            node temp = Head;

            for(int i = 1; i < pos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            Count--;
        }
    }

    public void Display()       // To display the LL
    {
        if(Head == null && Tail == null)
        {
            return;
        }

        System.out.println("Elements of linked list are :");

        node temp = Head;

        do
        {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }
        while(temp != Head);

        System.out.print("NULL\n");
    }

    public int CountNode()      // To count number of nodes in LL
    {
        return Count;
    }
}

class SCLL
{
    public static void main(String args[])
    {
        Scanner sobj = new Scanner(System.in);
        SinglyCLL obj = new SinglyCLL();

        int choice = 1, pos = 0, value = 0;

        while (choice != 0)
        {
            System.out.println("Choose from following options : ");

            System.out.println("1. InsertFirst");
            System.out.println("2. InsertLast");
            System.out.println("3. InsertAtPos");
            System.out.println("4. DeleteFirst");
            System.out.println("5. DeleteLast");
            System.out.println("6. DeleteAtPos");
            System.out.println("7. Display the linked list");
            System.out.println("8. Count the number of nodes");
            System.out.println("9. Exit\n");
            
            System.out.print("Enter your choice : ");
            choice = sobj.nextInt();

            switch (choice)
            {
                case 1:
                    System.out.print("Enter value : ");
                    value = sobj.nextInt();
                    obj.InsertFirst(value);
                    System.out.println("Node inserted successfully.");
                    System.out.println("----------------------------------------------------------");
                    break;

                case 2:
                    System.out.print("Enter value : ");
                    value = sobj.nextInt();
                    obj.InsertLast(value);
                    System.out.println("Node inserted successfully.");
                    System.out.println("----------------------------------------------------------");
                    break;
                
                case 3:
                    System.out.print("Enter value : ");
                    value = sobj.nextInt();
                    System.out.print("Enter position : ");
                    pos = sobj.nextInt();
                    obj.InsertAtPos(value, pos);
                    if(pos >= 1 && pos <= obj.CountNode()+1)
                    {
                        System.out.println("Node inserted successfully.");
                    }
                    System.out.println("----------------------------------------------------------");
                    break;
                
                case 4:
                    if(obj.CountNode() >= 1)
                    {
                        System.out.println("Node deleted successfully.");
                    }    
                    obj.DeleteFirst();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 5:
                    if(obj.CountNode() >= 1)
                    {
                        System.out.println("Node deleted successfully.");
                    }  
                    obj.DeleteLast();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    pos = sobj.nextInt();
                    if(pos >= 1 && pos <= obj.CountNode())
                    {
                        System.out.println("Node deleted successfully.");
                    }
                    obj.DeleteAtPos(pos);
                    System.out.println("----------------------------------------------------------");
                    break;

                case 7:
                    System.out.println("----------------------------------------------------------");
                    obj.Display();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 8:
                    System.out.println("----------------------------------------------------------");    
                    System.out.println( "Number of nodes are : " + obj.CountNode());
                    System.out.println("----------------------------------------------------------");
                    break;

                case 9:
                    System.out.println("Thank you!");
                    choice = 0;
                    System.out.println("----------------------------------------------------------");
                    break;

                default:
                    System.out.println("Invalid choice!");
                    System.out.println("----------------------------------------------------------");
                    break;
            }
        }

        sobj.close();
    }
}