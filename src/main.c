#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* Insert(struct TreeNode *root, int val) {
    if(root==NULL) {
        struct TreeNode *aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->left = NULL;
        aux->right = NULL;
        aux->val = val;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Insert(root->left, val);
        } else {
            root->right = Insert(root->right, val);
        }
        return root;
    }
}

int MaiorDiametro(struct TreeNode *root, int *maior) {
    
    if(root==NULL) {
        return 0;
    }

    int esq = MaiorDiametro(root->left, maior);
    int dir = MaiorDiametro(root->right, maior);

    int caminhoEsq = 0;
    int caminhoDir = 0;

    if(root->left && root->left->val == root->val) {
        caminhoEsq = esq + 1;
    }

    if(root->right && root->right->val == root->val) {
        caminhoDir = dir + 1;
    }

    int diametroAtual = caminhoEsq + caminhoDir;

    if(diametroAtual > *maior) {
        *maior = diametroAtual;
    }

    if(caminhoEsq > caminhoDir) {
        return caminhoEsq;
    } else {
        return caminhoDir;
    }
}

int longestUnivaluePath(struct TreeNode* root) {

    int maior = 0;

    MaiorDiametro(root, &maior);

    return maior;
}

int main() {
    
    struct TreeNode* arv = NULL; 

    arv = Insert(arv, 5);
    arv = Insert(arv, 5);
    arv = Insert(arv, 5);
    arv = Insert(arv, 3);
    arv = Insert(arv, 1);
    arv = Insert(arv, 4);

    printf("Maior diametro dom nodos de mesmo valor da arvore: %d", longestUnivaluePath(arv));

    return 0;
}
