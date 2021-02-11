
public class MyLinkedList {
	
	public class Node{
		public int val;
		public Node next;
		public Node prev;
		
		public Node(int i){
			val = i;
		}
		
		public void setNext(Node n){
			next = n;
		}
		public void setPrev(Node n){
			prev = n;
		}
		public Node getNext(){
			return next;
		}
		public Node getPrev(){
			return prev;
		}
	}
	
	public Node head;
	public Node tail;
	public int size;
	
	public MyLinkedList(){
		size = 0;
	}
	
	public void add(int i){
		Node n = new Node(i);
		if(head == null){
			head = n;
			tail = n;
		}else{
			boolean done = false;
			Node cur = head;
			while(!done){
				if(cur.next == null){
					cur.next = n;
					n.prev = cur;
					tail = n;
					done = true;
				}else{
					cur = cur.next;
				}
			}
		}
		size++;
	}
	
	public int get(int i){
		int j = 0;
		Node cur = head;
		while(j < i){
			cur = cur.next;
			j++;
		}
		return cur.val;
	}
	
	public Node getNode(int i){
		int j = 0;
		Node cur = head;
		while(j < i){
			cur = cur.next;
			j++;
		}
		return cur;
	}
	
	public void clear(){
		head = null;
		tail = null;
	}
	
	public void cutf(int num){
		if(num == 0){
			return;
		}
		Node newHead = this.getNode(num);
		Node newTail = newHead.prev;
		newTail.next = null;
		newHead.prev = null;
		head.prev = tail;
		tail.next = head;
		head = newHead;
		tail = newTail;
		
	}
	
	public MyLinkedList dealWithF(int n){
		int[] arr = new int[size];
		arr[0] = head.val;
		int i = 0;
		Node cur = head.getNext();
		while(cur != null){
			i = i+n;
			arr[i%size] = cur.val;
			cur = cur.next;
		}
		i = 0;
		MyLinkedList made = new MyLinkedList();
		while(i<size){
			made.add(arr[i]);
			i++;
		}
		return made;
	}
	
	public MyLinkedList dealWithB(int n){
		int[] arr = new int[size];
		arr[0] = tail.val;
		int i = 0;
		Node cur = tail.prev;
		while(cur != null){
			i = i+n;
			arr[i%size] = cur.val;
			cur = cur.prev;
		}
		i = size - 1;
		MyLinkedList made = new MyLinkedList();
		while(i>-1){
			made.add(arr[i]);
			i--;
		}
		return made;
	}
	
	public int getIndexOf(int i){
		int j = 0;
		int curVal = head.val;
		Node cur = head;
		while(curVal != i){
			cur = cur.next;
			curVal = cur.val;
			j++;
		}
		return j;
	}
}
