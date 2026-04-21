#include "CloudNode.hpp"

CloudNode::CloudNode(string server_name, int limit_gb)
:server_name(server_name), limit_gb(limit_gb), used_gb(0){
    Formatter::printCtor(this->server_name);
}

CloudNode::CloudNode(const CloudNode& other)
:server_name((other.server_name) + "_backup"), limit_gb(other.limit_gb), used_gb(0) {
    Formatter::printCCtor(this->server_name);
}

CloudNode& CloudNode::operator=(const CloudNode& other) {
    if (this == &other) return *this;

    if (other.used_gb + 2 >= this->limit_gb) {
        this->used_gb = this->limit_gb;
    }
    else {
        this->used_gb = other.used_gb + 2;
    }

    Formatter::printAssign(this->server_name); 
    return *this;
}

CloudNode::~CloudNode() {
    Formatter::printDtor(server_name);
}

CloudNode CloudNode::operator+(int n) {
    CloudNode res(*this);
    res.limit_gb += n;
    return res;
}

CloudNode CloudNode::operator-(int n) {
    CloudNode res(*this);
    res.limit_gb -= n;
    if (res.limit_gb < 0) res.limit_gb = 0;
    return res;
}

void systemWipe(CloudNode& node) {
    node.limit_gb = 0;
    node.used_gb = 0;
}