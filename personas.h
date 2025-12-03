#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#ifndef PERSONA
#define PERSONA

class AVL;

class Persona{
    private:
        string nombre = "N/A";
        double influencia = 0.00;
        Persona *left = NULL, *right = NULL;
	    int level = 0, balance = 0;
	    Persona* predecesor();
    public:
        Persona();
        Persona(string n, double i);
        Persona(string n);
        void print();
        string get_nombre() const;
        double get_influencia() const;
        void set_nombre(string n);
        void set_influencia(double i);
        void add(string, double);
        bool find(double);
        void remove(double);
        void removeChilds();
        void inorder(stringstream&) const;
        void preorder(stringstream&) const;
        int max_depth();
        Persona* check_tree(double*, Persona*, bool*);
        Persona* balance_tree();
        Persona* rot_left(Persona* );
        Persona* rot_right(Persona* );
        Persona* rot_left_right(Persona* );
        Persona* rot_right_left(Persona* );
        friend class AVL;
};

Persona::Persona(){}

Persona::Persona(string n, double i){
    nombre = n;
    influencia = i;
}

Persona::Persona(string n){
    nombre = n;
    influencia = 0.00;
}

void Persona::print(){
    cout << nombre << " " << influencia << "%" << endl;
}

string Persona::get_nombre() const{
    return nombre;
}

double Persona::get_influencia() const{
    return influencia;
}

void Persona::set_nombre(string n){
    nombre = n;
}

void Persona::set_influencia(double i){
    influencia = i;
}

 
void Persona::add(string nam, double val) {
	if (val < influencia) {
		if (left != 0) {
			return left->add(nam, val);
		} else {
			left = new Persona(nam, val);
		}
	} else {
		if (right != 0) {
			return right->add(nam, val);
		} else {
			right = new Persona(nam, val);
		}
	}
}
 
bool Persona::find(double val) {
	if (val == influencia) {
		return true;
	} else if (val < influencia) {
		return (left != 0 && left->find(val));
	} else if (val > influencia) {
		return (right != 0 && right->find(val));
	}
}

 
Persona* Persona::predecesor() {
	Persona *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Persona *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

 
void Persona::remove(double val) {
	Persona * succ, *old;

	if (val < influencia) {
		if (left != 0) {
			if (left->influencia == val) {
				old = left;
				succ = left->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > influencia) {
		if (right != 0) {
			if (right->influencia == val) {
				old = right;
				succ = right->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
}

 
void Persona::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

 
void Persona::inorder(stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	aux << nombre << " " << influencia << "%" << endl;
	if (right != 0) {
		right->inorder(aux);
	}
}

 
void Persona::preorder(stringstream &aux) const {
	aux << "(" << nombre << " " << influencia << "% " << level << " " << balance << ")";
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

 
int Persona::max_depth() {
	int le =0 , ri = 0;
	if (left != 0)
		le = left->max_depth() + 1;
	if (right != 0)
		ri = right->max_depth() + 1;
	if(le > ri)
		level = le;
	else
		level = ri;
	balance = le - ri;
	return level;
}

 
Persona* Persona::check_tree(double *check_val, Persona *parent, bool *checked) {
    Persona *le = 0, *ri = 0;
    
    if (left != 0)
        left = left->check_tree(check_val, this, checked);
    if (right != 0)
        right = right->check_tree(check_val, this, checked);
    
    max_depth();
    
    if (*checked == false && (balance > 1 || balance < -1)) {
        Persona* a = balance_tree();
        *check_val = influencia;
        *checked = true;
        return a;
    }
    
    return this;
}

 
Persona* Persona::balance_tree() {
    Persona *a = this, *le = left, *ri = right;
    
    if (balance > 0) {
        if (le->balance > 0) {
            a = rot_right(a);
        } else {
            a = rot_left_right(a);
        }
    } else {
        if (ri->balance < 0) {
            a = rot_left(a);
        } else {
            a = rot_right_left(a);
        }
    }

    if (a->left != 0)
        a->left->max_depth();
    if (a->right != 0)
        a->right->max_depth();
    a->max_depth();
    
    return a;
}

 
Persona* Persona::rot_left(Persona* a){
	Persona *b, *temp = 0;
	if (a->right != 0){
		b = a->right;
		if (b->left != 0)
			temp = b->left;
		b->left = a;
		if(temp != 0){
			a->right = temp;
		}else{
			a->right = 0;
		}
	}
	return b;
}

 
Persona* Persona::rot_right(Persona* a){
	Persona *b, *temp = 0;
	if (a->left != 0){
		b = a->left;
		if (b->right != 0)
			temp = b->right;
		b->right = a;
		if(temp != 0){
			a->left = temp;
		}else{
			a->left = 0;
		}
	}
	return b;
}

 
Persona* Persona::rot_left_right(Persona* a){
	a->left = rot_left(a->left);
	a = rot_right(a);
	return a;
}

 
Persona*  Persona::rot_right_left(Persona* a){
	a->right = rot_right(a->right);
	a = rot_left(a);
	return a;
}

#endif /* PERSONA */
