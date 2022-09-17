import java.util.*;

class node{
    public int data;
    public node next;
    public node prev;
}

class DoublyLLL
{
    public node Head;
    public int CountNode;

    public DoublyLLL()       // Constructor
    {
        Head = null;
        CountNode = 0;
    }

    public void InsertFirst(int value)
    {
        node newn = new node();

        newn.data = value;
        newn.next = null;

        if(Head == null)         // If LL is empty
        {
            Head = newn;
        }

        else        // If LL contains atleast 1 element
        {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }

        CountNode++;
    }

    public void InsertLast(int value)
    {
        node newn = new node();

        newn.data = value;
        newn.next = null;

        if(Head == null)         // If LL is empty
        {
            Head = newn;
        }

        else        // If LL contains atleast 1 element
        {
            node temp = Head;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev = temp;
        }

        CountNode++;
    }

    public void DeleteFirst()
    {
        if(Head == null)         // If LL is empty
        {
            return;
        }

        else if(Head.next == null && Head.prev == null)     // If LL contains only 1 element
        {
            Head = null;
        }

        else        // If LL contains more than 1 element
        {
            Head = Head.next;
            Head.prev = null;
        }

        CountNode--;
    }

    public void DeleteLast()
    {
        if(Head == null)         // If LL is empty
        {
            return;
        }

        else if(Head.next == null && Head.prev == null)     // If LL contains only 1 element
        {
            Head = null;
        }

        else        // If LL contains more than 1 element
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

    public void InsertAtPos(int value, int pos)
    {
        if(pos < 0 || pos > CountNode+1)
        {
            System.out.println("Invalid position!");
            return;
        }

        if(pos == 1)        // InsertFirst
        {
            InsertFirst(value);
        }

        else if(pos == CountNode+1)     // InsertLast
        {
            InsertLast(value);
        }

        else        // Inserting at any random position
        {
            node newn = new node();

            newn.data = value;
            newn.next = null;

            node temp = Head;

            for(int i = 1; i < (pos-1); i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            newn.prev = temp;
            temp.next = newn;

            CountNode++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 0 || pos > CountNode)
        {
            System.out.println("Invalid position!");
            return;
        }

        if(pos == 1)        // DeleteFirst
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
            temp.next.prev = temp;

            CountNode--;
        }
    }

    public void Display()        // To display the LL
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

class DLLL
{
    public static void main(String args[])
    {
        DoublyLLL obj = new DoublyLLL();
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