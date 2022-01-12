struct ListNode {
    data: i32,
    next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new() -> Self {
        ListNode {
            data: 0,
            next: None,
        }
    }
    fn from_vec(&mut self, vec: Vec<i32>) -> &Self {
        for i in vec.iter() {
            self.next = Some(Box::new(ListNode {
                data: *i,
                next: self.next.take(),
            }));
        }
        self
    }
    fn merge_two_lists(&mut self, list1: ListNode, list2: ListNode) -> &Self {
        let mut l1 = list1.next;
        let mut l2 = list2.next;
        let mut ptr3 = self;
        while let (Some(n1), Some(n2)) = (l1.as_ref(), l2.as_ref()) {
            if n1.data > n2.data {
                ptr3.next = l1;
                ptr3 = ptr3.next.as_mut().unwrap();
                l1 = ptr3.next.take();
            } else {
                ptr3.next = l2;
                ptr3 = ptr3.next.as_mut().unwrap();
                l2 = ptr3.next.take();
            }
            if let Some(n) = l1.as_ref() {
                println!("l1 = {}", n);
            }
            if let Some(n) = l2.as_ref() {
                println!("l2 = {}", n);
            }
        }
        ptr3.next = if l1.is_some() { l1 } else { l2 };
        ptr3
    }
}

impl std::fmt::Display for ListNode {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "[]")?;
        let mut p = self;
        while let Some(ref next) = p.next {
            write!(f, " -> {}", next.data)?;
            p = next;
        }
        Ok(())
    }
}

pub fn main() {
    let mut list1 = ListNode::new();
    let mut list2 = ListNode::new();
    let mut list3 = ListNode::new();
    list1.from_vec(vec![1, 3, 5, 7]);
    list2.from_vec(vec![2, 4]);
    list3.merge_two_lists(list1, list2);
    println!("{}", list3);
}
