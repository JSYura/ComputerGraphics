#include "find_all_intersecting_pairs_using_AABBTrees.h"
#include "box_box_intersect.h"
// Hint: use a list as a queue
#include <list>

void find_all_intersecting_pairs_using_AABBTrees(
  const std::shared_ptr<AABBTree> & rootA,
  const std::shared_ptr<AABBTree> & rootB,
  std::vector<std::pair<std::shared_ptr<Object>,std::shared_ptr<Object> > > & 
    leaf_pairs)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    std::list<std::pair<std::shared_ptr<Object>, std::shared_ptr<Object>>> queue;
    if (box_box_intersect(rootA->box, rootB->box)){
        queue.emplace_back(rootA, rootB);
    }
    while (!queue.empty()){
        std::shared_ptr<Object> object_A = queue.front().first;
        std::shared_ptr<Object> object_B = queue.front().second;
        queue.pop_front();
        std::shared_ptr<AABBTree> a = std::dynamic_pointer_cast<AABBTree>(object_A);
        std::shared_ptr<AABBTree> b = std::dynamic_pointer_cast<AABBTree>(object_B);
        if (!a and !b){
            leaf_pairs.emplace_back(object_A, object_B);
        } else if(!a){
            if(box_box_intersect(object_A->box, b->left->box)) {
                queue.emplace_back(object_A, b->left);
            }
            if (box_box_intersect(object_A->box, b->right->box)) {
                queue.emplace_back(object_A, b->right);
            }
        } else if(!b){
            if(box_box_intersect(a->left->box, object_B->box)) {
                queue.emplace_back(a->left, object_B);
            }
            if (box_box_intersect(a->right->box, object_B->box)) {
                queue.emplace_back(a->right, object_B);
            }
        } else{
            if (box_box_intersect(a->left->box, b->left->box)) {
                queue.emplace_back(a->left, b->left);
            }
            if (box_box_intersect(a->left->box, b->right->box)) {
                queue.emplace_back(a->left, b->right);
            }
            if (box_box_intersect(a->right->box, b->right->box)) {
                queue.emplace_back(a->right, b->right);
            }
            if (box_box_intersect(a->right->box, b->left->box)) {
                queue.emplace_back(a->right, b->left);
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
