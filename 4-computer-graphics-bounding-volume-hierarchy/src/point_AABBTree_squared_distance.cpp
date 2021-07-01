#include "point_AABBTree_squared_distance.h"
#include <queue> // std::priority_queue
#include "CloudPoint.h"

typedef std::pair<double, std::shared_ptr<Object>> num_ptr_pair;

bool point_AABBTree_squared_distance(
    const Eigen::RowVector3d & query,
    const std::shared_ptr<AABBTree> & root,
    const double min_sqrd,
    const double max_sqrd,
    double & sqrd,
    std::shared_ptr<Object> & descendant)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here
    std::priority_queue<num_ptr_pair, std::vector<num_ptr_pair>, std::greater<num_ptr_pair>> queue;
    queue.push(std::make_pair(point_box_squared_distance(query, root->box), root));
    std::pair<double, std::shared_ptr<Object>> curr_pair;
    double min_dist = std::numeric_limits<double>::infinity();
    double left_dist, right_dist;
    while(!queue.empty()){
        curr_pair = queue.top();
        queue.pop();
        double subtree_dist = curr_pair.first;
        if (subtree_dist < min_dist && subtree_dist >= min_sqrd && subtree_dist <= max_sqrd){
            std::shared_ptr<CloudPoint> tmp = std::dynamic_pointer_cast<CloudPoint>(curr_pair.second);
            if(tmp){
                min_dist = subtree_dist;
                descendant = tmp;
            }else{
                std::shared_ptr<AABBTree> tree_node = std::dynamic_pointer_cast<AABBTree>(curr_pair.second);
                left_dist = point_box_squared_distance(query, tree_node->left->box);
                queue.push(std::make_pair(left_dist, tree_node->left));
                right_dist = point_box_squared_distance(query, tree_node->right->box);
                queue.push(std::make_pair(right_dist, tree_node->right));
            }
        }
    }
    sqrd = min_dist;
    return (min_dist >= min_sqrd && min_dist <= max_sqrd);
  ////////////////////////////////////////////////////////////////////////////
}
