#include "AABBTree.h"

// See AABBTree.h for API
bool AABBTree::ray_intersect(
  const Ray& ray,
  const double min_t,
  const double max_t,
  double & t,
  std::shared_ptr<Object> & descendant) const 
{
  ////////////////////////////////////////////////////////////////////////////
    if (!ray_intersect_box(ray, this->box, min_t, max_t)){
        return false;
    }
    double left_tree;
    double right_tree;
    std::shared_ptr<Object> left_descendant;
    std::shared_ptr<Object> right_descendant;
    bool left_hit = false;
    bool right_hit = false;

    if (this->left){
        left_hit = this->left->ray_intersect(ray, min_t, max_t, left_tree, left_descendant);
        if (left_hit && !left_descendant){
            left_descendant = this->left;
        }
    }
    if (this->right){
        right_hit = this->right->ray_intersect(ray, min_t, max_t, right_tree, right_descendant);
        if (right_hit && !right_descendant){
            right_descendant = this->right;
        }
    }

    if (left_hit && right_hit){
        t = left_tree < right_tree? left_tree: right_tree;
        descendant = left_tree < right_tree? left_descendant: right_descendant;
        return true;
    } else if (left_hit) {
        t = left_tree;
        descendant = left_descendant;
        return true;
    } else if (right_hit) {
        t = right_tree;
        descendant = right_descendant;
        return true;
    } else {
        return false;
    }
  ////////////////////////////////////////////////////////////////////////////
}

