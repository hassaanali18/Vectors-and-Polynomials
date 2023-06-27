#include<iostream>
using namespace std;

class Poly
{
    class Term
    {
    public:
        double coeff;
        int exponent;
        Term* next;
        Term(double c, int e)
        {
            coeff = c;
            exponent = e;
            next = nullptr;
        }
        ~Term()
        {}
    };
    Term* head;

public:
    Poly()
    {
        head = NULL;
    }

    ~Poly()
    {
        Term* temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(double co, int expo);
    Poly operator+(const Poly& obj);
    Poly operator*(const Poly& obj);
    double evaluate(const double eval);
    void print();
    void operator=(Poly& obj);
};

void Poly::operator=(Poly& obj)
{
    head = obj.head;
}

void Poly::insert(double co, int expo)
{
    Term* temp = new Term(co, expo);
    if (head == nullptr || expo > head->exponent)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Term* current = head;
        while ((current->next != nullptr) && (expo < current->next->exponent))
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

Poly Poly::operator+(const Poly& obj)
{
    Poly res;
    Term* temp1 = head;
    Term* temp2 = obj.head;

    while ((temp1 != NULL) && (temp2 != NULL))
    {
        if (temp1->exponent > temp2->exponent)
        {
            res.insert(temp1->coeff, temp1->exponent);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            res.insert(temp2->coeff, temp2->exponent);
            temp2 = temp2->next;
        }
        else
        {
            double sum = temp1->coeff + temp2->coeff;

            if (sum != 0)
            {
                res.insert(sum, temp1->exponent);

            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return res;
}

Poly Poly::operator*(const Poly& obj)
{
    Poly res;
    Term* temp1 = head;

    while (temp1 != NULL)
    {
        Term* temp2 = obj.head;
        while (temp2 != NULL)
        {
            double prod1 = temp1->coeff * temp2->coeff;
            int prod2 = temp1->exponent + temp2->exponent;
            res.insert(prod1, prod2);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return res;
}

double Poly::evaluate(const double eval)
{
    double res = 0;
    Term* temp = head;

    while (temp != NULL)
    {
        res += temp->coeff * pow(eval, temp->exponent);
        temp = temp->next;
    }
    return res;
}

void Poly::print()
{
    Term* temp = head;

    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->exponent;
        if (temp->next != NULL)
        {
            cout << "+";
        }
        temp = temp->next;
    }
}

int main()
{
    Poly p1, p2;
    int size, expo;
    double coeff;
    cout << "Enter The Size Of The First Polynomial: " << endl;
    cin >> size;

    cout << "Enter The Coefficient And Exponent Of The First Polynomial: " << endl;

    for (int i = 1; i <= size; i++)
    {
        cin >> coeff >> expo;
        p1.insert(coeff, expo);
    }

    cout << "Enter The Size Of The Second Polynomial: " << endl;
    cin >> size;

    cout << "Enter The Coefficient And Exponent Of The Second Polynomial: " << endl;

    for (int i = 1; i <= size; i++)
    {
        cin >> coeff >> expo;
        p2.insert(coeff, expo);
    }

    Poly sum = p1 + p2;
    Poly product = p1 * p2;

    cout << "Polynomial 1: " << endl;
    p1.print();
    cout << endl;

    cout << "Polynomial 2: " << endl;
    p2.print();
    cout << endl;

    cout << "Sum Of The Polynomials: " << endl;
    sum.print();
    cout << endl;

    cout << "Product Of The Polynomials: " << endl;
    product.print();
    cout << endl;

    double eval;
    cout << "Enter The Value You Want To Evaluate First Polynomial: " << endl;
    cin >> eval;

    cout << "Evaluation Of Polynomial 1 At X = " << eval << ": " << p1.evaluate(eval) << endl;

    cout << "Enter The Value You Want To Evaluate Second Polynomial: " << endl;
    cin >> eval;
    cout << "Evaluation Of Polynomial 2 At X = " << eval << ": " << p2.evaluate(eval) << endl;
}