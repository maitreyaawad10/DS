import java.util.Scanner;

class node {
    public int data;
    public node next;
}

class SinglyLLL {
    public node Head;
    public int CountNode;

    public SinglyLLL()          // Constructor 
    {
        Head = null;
        CountNode = 0;
    }

    public void InsertFirst(int no) 
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if (Head == null)       // IF LL IS EMPTY
        {
            Head = newn;
        }

        else        // IF LL CONTAINS ATLEAST 1 ELEMENT
        {
            newn.next = Head;
            Head = newn;
        }

        CountNode++;
    }

    public void InsertLast(int no) 
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if (Head == null)       // IF LL IS EMPTY
        {
            Head = newn;
        }

        else        // IF LL CONTAINS ATLEAST 1 ELEMENT
        {
            node temp = Head;

            while (temp.next != null) 
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        CountNode++;
    }

    public void DeleteFirst() 
    {
        if(CountNode == 0)      // IF LL IS EMPTY
        {
            return;
        }

        else if(CountNode == 1)     // IF LL CONTAINS ONLY 1 ELEMENT
        {
            Head = null;
        }

        else        // IF LL CONTAINS MORE THAN 1 ELEMENT
        {
            node temp = Head;
            Head = Head.next;
            temp = null;
        }

        CountNode--;
    }

    public void DeleteLast() 
    {
        if(CountNode == 0)      // IF LL IS EMPTY
        {
            return;
        }

        else if(CountNode == 1)     // IF LL CONTAINS ONLY 1 ELEMENT
        {
            Head = null;
        }

        else        // IF LL CONTAINS MORE THAN 1 ELEMENT
        {
            node temp = Head;

            while(temp.next.next != null)
            {
                temp = temp.next;
            }

            temp.next = null;
        }

        CountNode--;
    }   

    public void InsertAtPos(int no, int pos) 
    {
        if((pos < 1) || (pos > CountNode+1))
        {
            System.out.println("Invalid position!");
            return;
        }

        else if(pos == 1)       // InsertFirst
        {
            InsertFirst(no);
        }

        else if(pos == CountNode+1)     // InsertLast
        {
            InsertLast(no);
        }

        else            //  // Inserting at any random position
        {
            node newn = new node();

            newn.data = no;
            newn.next = null;

            node temp = Head;

            for(int i = 1; i < (pos-1); i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            CountNode++;
        }
    }

    public void DeleteAtPos(int pos) 
    {
        if((pos < 1) || (pos > CountNode))
        {
            System.out.println("Invalid position!");
            return;
        }

        else if(pos == 1)       // DeleteFirst
        {
            DeleteFirst();
        }

        else if(pos == CountNode)       // DeleteLast
        {
            DeleteLast();
        }

        else        // Deleting at any random position
        {
            node temp = Head;

            for(int i = 1; i < (pos-1); i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            CountNode--;
        }
    }

    public void Display()       // To display the LL
    {
        System.out.println("Elements in linked list are : ");

        node temp = Head;

        while (temp != null) {
            System.out.print("| " + temp.data + " | -> ");
            temp = temp.next;
        }

        System.out.print("NULL\n");
    }

    public int Count()      // To count number of nodes in LL
    {
        return CountNode;
    }
}

class SLLL 
{
    public static void main(String arg[]) 
    {
        SinglyLLL obj = new SinglyLLL();
        Scanner sobj = new Scanner(System.in);
        int choice = 1;
        int value = 0, pos = 0;

        while (choice != 0)
        {
            System.out.println("Choose from following options : ");

            System.out.println("1. InsertFirst");
            System.out.println("2. DeleteFirst");
            System.out.println("3. InsertLast");
            System.out.println("4. DeleteLast");
            System.out.println("5. InsertAtPos");
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
                    System.out.println("----------------------------------------------------------");
                    break;

                case 2:
                    obj.DeleteFirst();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 3:
                    System.out.print("Enter value : ");
                    value = sobj.nextInt();
                    obj.InsertLast(value);
                    System.out.println("----------------------------------------------------------");
                    break;

                case 4:
                    obj.DeleteLast();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 5:
                    System.out.print("Enter value : ");
                    value = sobj.nextInt();
                    System.out.print("Enter position : ");
                    pos = sobj.nextInt();
                    obj.InsertAtPos(value, pos);
                    System.out.println("----------------------------------------------------------");
                    break;

                case 6:
                    System.out.print("Enter position : ");
                    pos = sobj.nextInt();
                    obj.DeleteAtPos(pos);
                    System.out.println("----------------------------------------------------------");
                    break;

                case 7:
                    System.out.println("----------------------------------------------------------");
                    obj.Display();
                    System.out.println("----------------------------------------------------------");
                    break;

                case 8:
                    System.out.println( "Number of nodes are : " + obj.Count());
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