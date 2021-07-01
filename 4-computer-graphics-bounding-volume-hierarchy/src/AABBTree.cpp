#include "AABBTree.h"
#include "insert_box_into_box.h"

AABBTree::AABBTree(
  const std::vector<std::shared_ptr<Object> > & objects,
  int a_depth): 
  depth(std::move(a_depth)), 
  num_leaves(objects.size())
{
  ////////////////////////////////////////////////////////////////////////////
    if (objects.size() <= 1)
        throw;
    else{
        for (int i = 0; i < objects.size(); i++){
            insert_box_into_box(objects[i]->box, this->box);
        }

        Eigen::RowVector3d axis_len;
        Eigen::RowVector3d axis_midpoint;

        for (int i = 0; i < 3; i++){
            axis_len[i] = abs(this->box.max_corner(i) - this->box.min_corner(i));
            axis_midpoint[i] = (this->box.max_corner(i) + this->box.min_corner(i)) / 2.0;
        }

        std::vector<std::shared_ptr<Object>> left_tree;
        std::vector<std::shared_ptr<Object>> right_tree;
        std::shared_ptr<Object> object;
        for (const auto & obj : objects){
            object = obj;
            if(axis_len[0] > axis_len[1] && axis_len[0] > axis_len[2]){
                if (object->box.center().x() < axis_midpoint[0])
                    left_tree.push_back(object);
                else
                    right_tree.push_back(object);
            }
            else if (axis_len[1] > axis_len[2]){
                if (object->box.center().y() < axis_midpoint[1])
                    left_tree.push_back(object);
                else
                    right_tree.push_back(object);
            }
            else{
                if (object->box.center().z() < axis_midpoint[2])
                    left_tree.push_back(object);
                else
                    right_tree.push_back(object);
            }
        }

        if (!left_tree.empty() && right_tree.empty() ) {
            right_tree.push_back(left_tree.back());
            left_tree.pop_back();
        }
        else if (left_tree.empty() && !right_tree.empty()) {
            left_tree.push_back(right_tree.back());
            right_tree.pop_back();
        }
        if (left_tree.size() == 1)
            this->left = left_tree[0];
        else if (left_tree.size() > 1)
            this->left = std::make_shared<AABBTree>(left_tree, a_depth + 1);
        else
            throw;
        if (right_tree.size() == 1)
            this->right = right_tree[0];
        else if (right_tree.size() > 1)
            this->right = std::make_shared<AABBTree>(right_tree, a_depth + 1);
        else
            throw;
    }
  ////////////////////////////////////////////////////////////////////////////
}
