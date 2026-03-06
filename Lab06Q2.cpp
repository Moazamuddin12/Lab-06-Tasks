#include <iostream>
#include <string>
using namespace std;

class Message {
private:
    string text;

public:
    void setText(string t) {
        text = t;
    }

    string getText() const {
        return text;
    }

    virtual string toString() const {
        return text;
    }
};

class SMS : public Message {
private:
    string recipientContactNo;

public:
    void setRecipientContactNo(string number) {
        recipientContactNo = number;
    }
	
    string getRecipientContactNo() const {
        return recipientContactNo;
    }

    string toString() const override {
        return "Contact No: " + recipientContactNo + 
               " | Message: " + getText();
    }
};

class Email : public Message {
private:
    string sender;
    string receiver;
    string subject;

public:
    void setSender(string s) {
        sender = s;
    }

    void setReceiver(string r) {
        receiver = r;
    }

    void setSubject(string s) {
        subject = s;
    }

    string getSender() const {
        return sender;
    }

    string getReceiver() const {
        return receiver;
    }

    string getSubject() const {
        return subject;
    }
    
    string toString() const override {
        return "Sender: " + sender +
               " | Receiver: " + receiver +
               " | Subject: " + subject +
               " | Message: " + getText();
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    string text = messageObject.getText();
    return text.find(keyword) != string::npos;
}

string encodeMessage(string message) {

    for(int i = 0; i < message.length(); i++) {

        if(message[i] >= 'A' && message[i] <= 'Y')
            message[i]++;

        else if(message[i] == 'Z')
            message[i] = 'A';

        else if(message[i] >= 'a' && message[i] <= 'y')
            message[i]++;

        else if(message[i] == 'z')
            message[i] = 'a';
    }

    return message;
}


int main() {

    SMS sms1;
    sms1.setRecipientContactNo("03001234567");
    sms1.setText("Hello this is Moazam");

    cout << "SMS Details:\n";
    cout << sms1.toString() << endl;

    Email email1;
    email1.setSender("moazam@gmail.com");
    email1.setReceiver("friend@gmail.com");
    email1.setSubject("Meeting");
    email1.setText("This is Java");

    cout << "\nEmail Details:\n";
    cout << email1.toString() << endl;

    string keyword = "Java";
    if(ContainsKeyword(email1, keyword))
        cout << "\nKeyword found in email message.\n";
    else
        cout << "\nKeyword not found.\n";

    string encoded = encodeMessage(email1.getText());

    cout << "\nOriginal Message: " << email1.getText() << endl;
    cout << "Encoded Message: " << encoded << endl;

    return 0;
}
