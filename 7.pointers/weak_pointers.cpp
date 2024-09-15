// In C++, weak pointers are a type of smart pointer provided by the Standard Library through std::weak_ptr.
//  A weak pointer is a non-owning, weak reference to an object that is managed by a std::shared_ptr. 
//  It is primarily used to avoid circular references in cases where std::shared_ptr objects reference each
//   other, leading to memory leaks.

// Key Points:
// Non-Owning Reference: A std::weak_ptr does not contribute to the reference count of the object it points to. 
// Therefore, it doesn't keep the object alive on its own. It simply monitors the object managed by a std::shared_ptr.
// Breaking Cyclic Dependencies: std::weak_ptr is commonly used to break circular references. Without weak_ptr, 
// if two objects hold std::shared_ptr references to each other, they would never be deallocated because
//  their reference counts would never reach zero.
// Expiration and Locking: A std::weak_ptr can be converted to a std::shared_ptr via the lock() function, 
// but only if the object it points to still exists (i.e., the shared_ptr is still alive).
//  If the object has already been destroyed, lock() will return a nullptr

#include <iostream>
#include <memory>

class ChildNode;

class Node {
public:
    std::shared_ptr<ChildNode> child;  // shared ownership of ChildNode
    ~Node() { std::cout << "Node destroyed\n"; }
};

class ChildNode {
public:
    std::shared_ptr<Node> parent;  // shared ownership of Node
    ~ChildNode() { std::cout << "ChildNode destroyed\n"; }
};

class ChildNodeWeakPtr;
class Node2 {
public:
    std::shared_ptr<ChildNodeWeakPtr> child;  // shared ownership of ChildNode
    ~Node2() { std::cout << "Node destroyed\n"; }
};

class ChildNodeWeakPtr {
public:
    std::shared_ptr<Node> parent;  // shared ownership of Node
    ~ChildNodeWeakPtr() { std::cout << "ChildNode destroyed\n"; }
};

int main() {
    // Create a Node and ChildNode
    std::shared_ptr<Node> node = std::make_shared<Node>();
    std::shared_ptr<ChildNode> childNode = std::make_shared<ChildNode>();

    // Circular reference
    node->child = childNode;
    childNode->parent = node;

    // Memory leak: Neither object gets destroyed

    std::shared_ptr<Node2> node2 = std::make_shared<Node2>();
    std::shared_ptr<ChildNodeWeakPtr> childNodeWeak = std::make_shared<ChildNodeWeakPtr>();

    //breaks the Circular reference
    node->child = childNode;
    childNodeWeak->parent = node;

    //now both destroyed
    return 0;
}
