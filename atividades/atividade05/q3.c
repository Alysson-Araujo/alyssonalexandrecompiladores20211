/*
lexp -> número | (op lexp-seq)
op -> +|-|*
lexp-seq -> lexp-seq lexp | lexp
*/

typedef enum
{
    Plus,
    Minus,
    Mult
} OpKind;

typedef enum
{
    OpK,
    ConstK,
    LexpSeqK
} LexpKind;

typedef enum
{
    LexpK
} LexpSeqKind;


/* a estrutura de um nó da árvore. Nessa árvore podemos ter OpKind, LexpKind, LexpSeqKind e um Value que representa
os números. */
typedef struct streeNode
{
    OpKind op;
    LexpKind lexp;
    LexpSeqKind LexpSeq;
    int Value; // é a contante, no caso o número.
    struct streetnode *leftchild, *rightchild; 
} STreeNode;
typedef STreeNode *SyntaxTree;