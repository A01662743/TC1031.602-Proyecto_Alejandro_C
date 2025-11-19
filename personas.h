/*
 * AVL.h
 *
 *  Created on: 11/10/2021
 *      Author: bvaldesa
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include <fstream>
#include "personas.h"
#include <iostream>

using namespace std;


class AVL {
private:
	Persona *root;

public:
	AVL();
	~AVL();
	bool empty() const;
	void add(string, double);
	bool find(double) const;
	void remove(double);
	void removeAll();
	string inorder() const;
	string preorder() const;
	void loadFromFile(string fileName);
};

AVL::AVL() : root(0) {}

AVL::~AVL() {
	removeAll();
}

 
bool AVL::empty() const {
	return (root == 0);
}

void AVL::add(string nam, double val) {
	if (root != 0) {
		if (!root->find(val)) {
			Persona  *temp;
			double check_val = false;
			bool aux = false;
			root->add(nam, val);
			root->max_depth();
			temp = root->check_tree(&check_val, 0, &aux);
			if (check_val == root->influencia){
				root = temp;
			}
			root->max_depth();
		}
	} else {
		root = new Persona(nam, val);
	}
}
 
void AVL::remove(double val) {
	if (root != 0) {
		if (val == root->influencia) {
			Persona *succ = root->predecesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
		root->max_depth();
		Persona  *temp;
		double check_val = false;
		bool aux = false;
		temp = root->check_tree(&check_val, 0, &aux);
		if (check_val == root->influencia){
			root = temp;
		}
		root->max_depth();
	}
}

 
void AVL::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

 
bool AVL::find(double val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

 
string AVL::inorder() const {
	stringstream aux;

	if (!empty()) {
		root->inorder(aux);
	}
	return aux.str();
}

 
string AVL::preorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

//formato ej: Alex 50.4
void AVL::loadFromFile(string fileName) {
    ifstream file(fileName.c_str());
    string line;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string nombre;
            double influencia;

            if (ss >> nombre >> influencia) {
                if (influencia >= 0 && influencia <= 100) {
                    this->add(nombre, influencia);
                } else {
                    cerr << "Fuera de rango (0-100) para " << nombre << ". Saltando registro." << endl;
                }
            } else {
                cerr << "Advertencia: Formato de línea incorrecto. Saltando línea: " << line << endl;
            }
        }
        file.close();
		
    } else {
        cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
    }
}

#endif /* AVL_H_ */
