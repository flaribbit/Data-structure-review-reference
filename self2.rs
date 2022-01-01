struct BiTree {
    value: char,
    left: Option<Box<BiTree>>,
    right: Option<Box<BiTree>>,
}

impl BiTree {
    fn create_node(iter: &mut std::str::Chars) -> Option<Box<BiTree>> {
        let value = iter.next().unwrap();
        if value == '.' {
            return None;
        }
        Some(Box::new(BiTree {
            value,
            left: BiTree::create_node(iter),
            right: BiTree::create_node(iter),
        }))
    }
    fn create(s: &str) -> Option<Box<BiTree>> {
        let mut chars = s.chars();
        BiTree::create_node(&mut chars)
    }
    fn pre_order(&self) {
        print!("{}", self.value);
        if let Some(ref left) = self.left {
            left.pre_order();
        }
        if let Some(ref right) = self.right {
            right.pre_order();
        }
    }
    fn swap(&mut self) {
        if let Some(ref mut left) = self.left {
            left.swap();
        }
        if let Some(ref mut right) = self.right {
            right.swap();
        }
        std::mem::swap(&mut self.left, &mut self.right);
    }
}

fn main() {
    // let mut bitree = BiTree::create("abd..e..c.f..").unwrap();
    let mut bitree = BiTree::create("ab..cd...").unwrap();
    bitree.pre_order();
    println!("");
    bitree.swap();
    bitree.pre_order();
}
