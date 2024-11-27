#include <algorithm> /* max_element, count, copy, std::find */
#include <assert.h> /* assert */
#include <cstdio> /* printf */
#include <cstdlib>
#include <bits/stdc++.h> /* MAX_INT ; MIN_INT */
#include <iostream>
#include <math.h> /* log10 */
#include <memory> /* auto_ptr */
#include <numeric> /* std::accumulate */
#include <queue> /* priority_queue */
#include <random> /* random_device */
#include <regex>
#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <utility> /* std::pair, std::make_pair, move */
#include <vector>

using namespace std;

#ifndef HEADER_H_SOLUTION
#define HEADER_H_SOLUTION

#define DEBUG

#ifdef DEBUG
#define DEBUG_MSG(x) do { std::cout << x;} while( false )
#else
#define DEBUG_MSG(x) do { } while( false )
#endif



/* behaviorial design pattern */
namespace BEHAVIORIAL_DP {


  /* Null object */
  class Logger {
  public:
    virtual ~Logger() {};
    virtual void log(const std::string& message) = 0;
  };
  
  
  class ConsoleLogger : public Logger {
  public:
    void log(const std::string& message) override {
      cout << message << "\n";
    };
  };

  
  class FileLogger : public Logger {
    std::string _filePath;
  public:
    FileLogger(const std::string& filePath) : _filePath(filePath) {};
    void log(const std::string& message) override {
      cout << "Printing message to file " << _filePath << ": "
           << message << "\n";
    };
  };

  
  class ApiLogger : public Logger {
    std::string _url;
  public:
    ApiLogger(const std::string& url) : _url(url) {};
    void log(const std::string& message) override {
      cout << "Sending message to api " << _url << ": "
           << message << "\n";
    };
  };
  
  
  class NullLogger : public Logger {
  public:
    void log(const std::string& message) override {
      cout << "do nothing..." << message << endl;
    };
  };


  class SomeTask {
    Logger* _logger = nullptr;
  public:
    SomeTask() {
      _logger = new NullLogger;
    };
    SomeTask(Logger* logger) : _logger(logger) {};
    ~SomeTask() { delete _logger; };
    void execute() {
      // Do some stuff...
      if (_logger) {
        _logger->log("Did some stuff\n");
      }

      // Do some other stuff...
      if (_logger) {
        _logger->log("Did some other stuff\n");
      }

      // One last thing...
      if (_logger) {
        _logger->log("Task complete!\n");
      }

    }
  };
  
  
  /* Memento method */
  class CanvasM; // reused in previous example
  class CanvasMemento {
    friend class CanvasM;
    const std::vector<std::string> _shapes;
  public:
    CanvasMemento(std::vector<std::string> shapes) : _shapes(shapes) {};
  };


  class CanvasM {
  private:
    std::vector<std::string> _shapes;
    std::vector<CanvasMemento*> _oldStates;
  public:
    ~CanvasM() {
      for (auto p : _oldStates) {
        delete p;
      }  
    };
    void addShape(const std::string& newShape) {
      _oldStates.push_back(new CanvasMemento(_shapes));
      _shapes.push_back(newShape);
    };
    void undo() {
      CanvasMemento* previousState = _oldStates.back();
      _oldStates.pop_back();
      _shapes = previousState->_shapes;
      delete previousState;
    };
    void clearAll() {
      _shapes.clear(); // empty _shapes vector
    };
    std::vector<std::string> getShapes() {return _shapes; };
  };

  /* Iterator method */
  class NumberIterator {
  public:
    virtual ~NumberIterator() {};
    virtual int next() = 0;
    virtual bool isFinished() = 0;
  };
  
  class ForwardsIterator : public NumberIterator {
  private:
    int _currentPosition;
    std::vector<int> _numbers;
  public:
    ForwardsIterator(std::vector<int>& numbers) : _numbers(numbers) {};
    int next() override {
      int current = _numbers.at(_currentPosition);
      _currentPosition += 1;
      return current;
    };
    bool isFinished() {
      return (_currentPosition >= (int)_numbers.size());
    };
  };
  
  
  class BackwardsIterator : public NumberIterator {
  private:
    int _currentPosition;
    std::vector<int> _numbers;
  public:
    BackwardsIterator(std::vector<int>& numbers) : _numbers(numbers) {};
    int next() override {
      int current = 
        _numbers.at((int)_numbers.size() - _currentPosition - 1);
      _currentPosition += 1;
      return current;
    };
    bool isFinished() {
      return (_currentPosition >= (int)_numbers.size());
    };
  };
  

  class NumberCollection {
  private:
    std::vector<int> _numbers;
  public:
    NumberCollection(const std::vector<int>& numbers) : 
      _numbers(numbers) {};
    NumberIterator* getForwardsIterator() {
      return (new ForwardsIterator(_numbers));
    }
    NumberIterator* getBackwardsIterator() {
      return (new BackwardsIterator(_numbers));
    }
  }; 

  /* Visitor method */
  class Visitor {
  public:
    virtual ~Visitor() {};
    virtual void handlePersonV(const std::string& name,
        const int& age) = 0;
    virtual void handleLandmarkV(
        const std::string& name, 
        const std::string& cityName) = 0;
    virtual void handleCarV(
        const std::string& make, 
        const std::string& model) = 0;
  };


  class DatabaseVisitor : public Visitor {
  public:
    void handlePersonV(const std::string& name,
        const int& age) override {
      cout << "Writing preson to database: " 
           << name << ", " << age << "\n";
    };
    void handleLandmarkV(
        const std::string& name, 
        const std::string& cityName) override {
      cout << "Writing landmark to database: " 
           << name << ", " << cityName << "\n";
    };
    virtual void handleCarV(
        const std::string& make, 
        const std::string& model) {
      cout << "Writing car to database: " 
           << make << ", " << model << "\n";
    };
  };
  
  
  class TextFileVisitor : public Visitor {
  public:
    void handlePersonV(const std::string& name,
        const int& age) override {
      cout << "Writing preson to file: " 
           << name << ", " << age << "\n";
    };
    void handleLandmarkV(
        const std::string& name, 
        const std::string& cityName) override {
      cout << "Writing landmark to file: " 
           << name << ", " << cityName << "\n";
    };
    virtual void handleCarV(
        const std::string& make, 
        const std::string& model) {
      cout << "Writing car to file: " 
           << make << ", " << model << "\n";
    };
  };
  
  
  class PersonV {
  private:
    std::string _name;
    int _age;
  public:
    PersonV(const std::string& name, const int& age) :
      _name(name), _age(age) {};
    void accept(Visitor* v) { v->handlePersonV(_name, _age); };
  };
  
  
  class LandmarkV {
  private:
    std::string _name;
    std::string _cityName;
  public:
    LandmarkV(const std::string& name, const std::string& cityName) :
      _name(name), _cityName(cityName) {};
    void accept(Visitor* v) { v->handleLandmarkV(_name, _cityName); };
  };
 
  
  class CarV {
  private:
    std::string _make;
    std::string _model;
  public:
    CarV(const std::string& make, const std::string& model) :
      _make(make), _model(model) {};
    void accept(Visitor* v) { v->handleCarV(_make, _model); };
  };


  /* Template method */
  class GreetingCardTemplate {
  protected:
    virtual std::string intro(const std::string& addresseeName) {
      return "Dear " + addresseeName + ",\n";
    };
    virtual std::string occasion() {
      return "Just writing to say hi! Hope all is \
well with you.\n";
    };
    virtual std::string closing(const std::string& senderName) {
      return "Sincerely,\n" + senderName + "\n";
    };
  public:
    std::string generate(const std::string& addresseeName,
        const std::string& senderName) {
      return intro(addresseeName) + 
             occasion() +
             closing(senderName); 
    };
  };

  
  class BirthdayCardTemplate : public GreetingCardTemplate {
  protected:
    std::string occasion() override {
      return "Happy birthday!! Hope you have a \
wonderful day and lots of cake.\n";
    };
  };
  
  
  class NewYearCardTemplate : public GreetingCardTemplate {
  protected:
    std::string intro(const std::string& addresseeName) override {
      return addresseeName + "!!!\n";
    };
    virtual std::string occasion() override {
      return "Happy New Years!!!! See you at the \
gym tomorrow!\n";
    };
  };


  /* Strategy method */
  class GreetingStrategy {
  public:
    virtual ~GreetingStrategy() {};
    virtual void greet(const std::string& name) = 0;
  };
  
  
  class FormalGreetingStrategy : public GreetingStrategy {
  public:
    void greet(const std::string& name) {
      cout << "Good morning " << name << ", how do you do?\n";
    }
  };
  
  
  class NormalGreetingStrategy : public GreetingStrategy {
  public:
    void greet(const std::string& name) {
      cout << "Hi " << name << ", how are you?\n";
    }
  };
  
  
  class InformalGreetingStrategy : public GreetingStrategy {
  public:
    void greet(const std::string& name) {
      cout << "Hey " << name << ", what's up?\n";
    }
  };
  
  
  class Person {
    GreetingStrategy* _greetingStrategy;
  public:
    Person(GreetingStrategy* greetingStrategy) :
   _greetingStrategy(greetingStrategy) {};
    ~Person() { delete _greetingStrategy; };
    void greet(const std::string& name) {
      _greetingStrategy->greet(name);
    }
  };

  /*
  class Person {
  public:
    virtual void greet(const std::string& name) = 0;
  };
 
  
  class BusinessPerson : public Person {
  public:
    void greet(const std::string& name) {
      cout << "Good morning " << name << ", how do you do?\n";
    }
  };


  class NormalPerson : public Person {
  public:
    void greet(const std::string& name) {
      cout << "Hi " << name << ", how are you?\n";
    }
  };
  
  
  class CoolPerson : public Person {
  public:
    void greet(const std::string& name) {
      cout << "Hey " << name << ", what's up?\n";
    }
  };

  // Uh oh - code deuplication of BusinessPerson!
  class Politician : public Person {
  public:
    void greet(const std::string& name) {
      cout << "Good morning " << name << ", how do you do?\n";
    };
  };
  */
  
  /* State method */
  class State {
  public:
    virtual ~State() {};
    virtual std::string getDescription() = 0;
    virtual State* getNextState() = 0;
  };


  class PurchasedState : public State {
    State* _nextState = nullptr;
  public:
    PurchasedState(State* nextState) : _nextState(nextState) {};
    std::string getDescription() override {
      return "Currnet State: PURCHASED - Will be shipping soon\n";
    }
    State* getNextState() override { return _nextState; };
  };
  
  
  class InTransitState : public State {
    State* _nextState = nullptr;
  public:
    InTransitState(State* nextState) : _nextState(nextState) {};
    std::string getDescription() override {
      return "Currnet State: IN_TRANSIT - Your item is on the way\n";
    }
    State* getNextState() override { return _nextState; };
  };
  
  
  class DeliveredState : public State {
    State* _nextState = nullptr;
  public:
    DeliveredState(State* nextState) : _nextState(nextState) {};
    std::string getDescription() override {
      return "Currnet State: DELIVERED - Your item has arrived\n";
    }
    State* getNextState() override { return _nextState; };
  
  };
  

  class Purchase {
  private:
    std::string _productName;
    //std::string _currentState;
    State* _currentState;
  public:
    Purchase(const std::string& productName,
        State* initialState) : 
      _productName(productName), 
      _currentState(initialState/*"PURCHASED"*/) {};
    
    std::string getDescription() {
      return _currentState->getDescription();
      /*
      std::string description = _productName + " - " +
        _currentState + "\n";

      if (_currentState == "PURCHASED") {
        description += "Will be shipping soon\n";
      } else if (_currentState == "IN_TRANSIT") {
        description += "Your item is on the way\n";
      } else if (_currentState == "DELIVERED") {
        description += "Your item has arrived\n";
      }

      return description;
      */
    };

    void goToNextState() {
      if ( _currentState->getNextState() ) {
        _currentState = _currentState->getNextState();
      } else {
        cout << "No more states!";
      }
      /*
      if (_currentState == "PURCHASED") {
        _currentState = "IN_TRANSIT";
      } else if (_currentState == "IN_TRANSIT") {
        _currentState = "DELIVERED";
      } else if (_currentState == "DELIVERED") {
        cout << "No more states!";
      }
      */
    };
  };


  /* Interpreter method includes 
   * 1. non-terminal expression
   * 2. terminal expression */
  class Expression {
  public:
    virtual ~Expression() {};
    virtual int evaluate() = 0;
  };

  // non-terminal expression
  class OperationExpression : public Expression {
    std::string _operatorSymbol;
    Expression* _leftHandSide;
    Expression* _rightHandSide;
  public:
    OperationExpression(const std::string& operatorSymbol,
        Expression* lhs, Expression* rhs) : 
   _operatorSymbol(operatorSymbol), _leftHandSide(lhs),
   _rightHandSide(rhs) {};

    int evaluate() {
      if (_operatorSymbol == "+") {
        return _leftHandSide->evaluate() + 
          _rightHandSide->evaluate();
      } else if (_operatorSymbol == "-") {
        return _leftHandSide->evaluate() - 
          _rightHandSide->evaluate();
      } else if (_operatorSymbol == "*") {
        return _leftHandSide->evaluate() *
          _rightHandSide->evaluate();
      } else {
        std::cout << "Unrecognized operator: " 
                  << _operatorSymbol;
        return 0;
      }
    };
  };

  // terminal expression
  class NumberExpression : public Expression {
    std::string _numberString;
  public:
    NumberExpression(const std::string& numberString) :
   _numberString(numberString) {};
    int evaluate() override {
      return std::stoi(_numberString);
    };
  };

  /* observer method includes
   * 1. Publisher
   * 2. Subscriber  */
  class Subscriber {
  public:
    // for publishers to use
    virtual ~Subscriber() {};
    virtual void notify(const std::string& publisherName,
                        const std::string& message) = 0;
    virtual std::string getName() = 0;
  };


  class Publisher {
  public:
    virtual ~Publisher() {};
    // for subscribers to use
    virtual void subscribe(Subscriber* subscriber) = 0;
    // for subscribers to use
    virtual void unsubscribe(Subscriber* subscriber) = 0;
    virtual void publish(const std::string& message) = 0;
  };


  class ChatGroup : public Publisher {
  private:
    std::string _groupName;
    std::vector<Subscriber*> _subscribers;
  public:
    ChatGroup(const std::string& name) : _groupName(name) {};
    // for subscribers to use
    void subscribe(Subscriber* subscriber) override {
      this->_subscribers.push_back(subscriber);
    };
    // for subscribers to use
    void unsubscribe(Subscriber* subscriber) override {
      _subscribers.erase(std::remove_if(
            _subscribers.begin(), _subscribers.end(),
            [subscriber](Subscriber* s) { return s->getName() == subscriber->getName(); }),
            _subscribers.end());
    };
    void publish(const std::string& message) override {
      for (auto subscriber : _subscribers) {
        subscriber->notify(_groupName, message);
      }
    };
  };


  class ChatUser : public Subscriber {
    std::string _userName;
  public:
    ChatUser(const std::string userName) : _userName(userName) {};
    void notify(const std::string& publisherName,
                const std::string& message) override {
      cout << _userName << " received a new message from "
           << publisherName << ": " << message << "\n";
    };
    std::string getName() override {
      return _userName;
    };
  };


  /* Mediator */
  class Mediator {
  public:
    virtual void mediate(const std::string& event) = 0;
  };


  class InterfaceElement {
  protected:
    string _name;
    bool _isVisible;
    Mediator* _mediator;
  public:
    InterfaceElement(const std::string& name, 
        bool isVisible, Mediator* mediator) : 
      _name(name), _isVisible(isVisible), _mediator(mediator) {};
    void setVisibility(bool isVisible) {
      this->_isVisible = isVisible;
    };
    std::string getDescription() {
      return (_isVisible ? 
          (_name + " is visible") : (_name + " is Not visible"));
    };
  };


  class ButtonElement : public InterfaceElement {
  public:
    ButtonElement(const std::string& name, 
        bool isVisible, Mediator* mediator) :
   InterfaceElement(name, isVisible, mediator) {};
    virtual ~ButtonElement() {};
    virtual void click() {
      _mediator->mediate(_name + " clicked");
    };
  };


  class TextBox : public InterfaceElement {
  private:
    std::string _textValue = "";
  public:
    TextBox(const std::string& name, 
        bool isVisible, Mediator* mediator) :
   InterfaceElement(name, isVisible, mediator) {};
    virtual ~TextBox() {};
    virtual void changeText(const std::string& newValue) {
      _textValue = newValue;
      if (newValue.empty()) {
        _mediator->mediate(_name + " empty");
      } else {
        _mediator->mediate(_name + " not empty");
      }
    };
  };


  class CheckBox : public InterfaceElement {
  private:
    bool _isChecked = false;
  public:
    CheckBox(const std::string& name, 
        bool isVisible, Mediator* mediator) : 
   InterfaceElement(name, isVisible, mediator) {};
    virtual ~CheckBox() {};
    virtual void setIsChecked(bool isChecked) {
      this->_isChecked = isChecked;
      if (isChecked) {
        _mediator->mediate(_name + " is checked");
      } else {
        _mediator->mediate(_name + " not unchecked");
      }
      
    };
  };

  /*
  class SubmitButton : public ButtonElement {
  public:
    SubmitButton() : ButtonElement("Submit button", false) {};
    void click() override {
      std::cout << "Submitted!";
    };
  };


  class NameTextBox : public TextBox {
    SubmitButton* _submitButton;
  public:
    NameTextBox(SubmitButton* submitButton) : 
      TextBox("Name textbox", true), 
      _submitButton(submitButton) {};
      void changeText(const std::string& newValue) override {
        if (newValue.empty()) {
          _submitButton->setVisibility(false);
        } else {
          _submitButton->setVisibility(true);
        }

        TextBox::changeText(newValue);
      };
  };


  class SpousesNameTextBox : public TextBox {
  public:
    SpousesNameTextBox() : 
      TextBox("Spouses's name textbox", false) {};
  };
  
  
  class IsMarriedCheckBox : public CheckBox {
  private:
    SpousesNameTextBox* _spousesNameTextBox;
  public:
    IsMarriedCheckBox(SpousesNameTextBox* spousesNameTextBox) : 
      CheckBox("Is married checkbox", true),
      _spousesNameTextBox(spousesNameTextBox) {};
    void setIsChecked(bool isChecked) override {
      if (isChecked) {
        _spousesNameTextBox->setVisibility(true);
      } else {
        _spousesNameTextBox->setVisibility(false);
      }
      CheckBox::setIsChecked(isChecked);
    };
  };
*/

  class UserInterface : public Mediator {
  private:
    TextBox* _nameTextBox;
    CheckBox* _isMarriedCheckBox;
    TextBox* _spousesNameTextBox;
    ButtonElement* _submitButton;
  public:
    UserInterface() {
      _nameTextBox = new TextBox("Name textbox", true, this);
      _isMarriedCheckBox = new CheckBox("Is married checkbox", true, this);
      _spousesNameTextBox = new TextBox("Spouse's name textxox", false, this);
      _submitButton = new ButtonElement("Submit button", false, this);
    };
    
    ~UserInterface() {
      delete _nameTextBox;
      delete _isMarriedCheckBox;
      delete _spousesNameTextBox;
      delete _submitButton;
    };
    
    void mediate(const std::string& event) override {
      cout << "Mediating event: " << event << "...\n";

      if (event == "Name textbox is empty") {
        _submitButton->setVisibility(false);
      } else if (event == "Name textbox is not empty") {
        _submitButton->setVisibility(true);
      } else if (event == "Is married checkbox is checked") {
        _isMarriedCheckBox->setVisibility(true);
      } else if (event == "Is married checkbox is unchecked") {
        _isMarriedCheckBox->setVisibility(false);
      } else if (event == "Submit button clicked") {
        std::cout << "Submitted\n";
      } else {
        std::cout << "Unrecognized event!\n";
      }
    };

    TextBox* getNameTextBox() {return _nameTextBox;};
    CheckBox* getIsMarriedCheckBox() {return _isMarriedCheckBox;};
    TextBox* getSpousesNameTextBox() {return _spousesNameTextBox;};
    ButtonElement* getSubmitButton() {return _submitButton;};
  };
  

  /* Command */
  class Canvas {
  private:
    std::vector<std::string> _shapes;
  public:
    void addShape(const std::string& newShape) {
      _shapes.push_back(newShape);
    };
    void clearAll() {
      _shapes.clear(); // empty _shapes vector
    };
    std::vector<std::string> getShapes() {return _shapes; };
  };


  class Command {
  public:
    virtual ~Command() {};
    virtual void execute() = 0;
  };


  // abstract class
  class Button {
  private:
    Command* _command;
  public:
    Button(Command* command) : _command(command) {};
    //virtual ~Button() {};
    //virtual void click() = 0;
    void click() {
      _command->execute();
    };
  };
  

  class AddShapeCommand : public Command {
  private:
    std::string _shapeName;
    Canvas* _canvas;
  public:
    AddShapeCommand(const std::string& shapeName, Canvas* canvas) :
   _shapeName(shapeName), _canvas(canvas) {};
    void execute() {
      _canvas->addShape(_shapeName);
    }
  };
  
  
  class ClearCommand : public Command {
  private:
    Canvas* _canvas;
  public:
    ClearCommand(Canvas* canvas) : _canvas(canvas) {};
    void execute() {
      _canvas->clearAll();
    }
  };
 
  /* 
  // concrete class
  class AddTriangleButton : public Button {
  private:
    Canvas* _canvas;
  public:
    AddTriangleButton(Canvas* canvas) : _canvas(canvas) {};
    void click() override {
      _canvas->addShape("triangle");
    };
  };

  
  // concrete class
  class AddSquareButton : public Button {
  private:
    Canvas* _canvas;
  public:
    AddSquareButton(Canvas* canvas) : _canvas(canvas) {};
    void click() override {
      _canvas->addShape("square");
    };
  };


  // concrete class
  class ClearButton : public Button {
  private:
    Canvas* _canvas;
  public:
    ClearButton(Canvas* canvas) : _canvas(canvas) {};
    void click() override {
      _canvas->clearAll();
    };
  };
  */

  /* Chain of responsibility */
  class StringValidator {
  public:
    virtual ~StringValidator() {};
    virtual StringValidator* 
      setNext(StringValidator* nextValidator) = 0;
    virtual std::string validate(std::string) = 0;
  };


  class BaseValidator : public StringValidator {
  protected:
    StringValidator* _next = nullptr;
  public:
    virtual ~BaseValidator() {delete _next;};
    StringValidator* setNext(StringValidator* nextValidator) override {
      _next = nextValidator;
      return nextValidator;
    };
    virtual std::string validate(std::string testString) override {
      if (this->_next) {
        // pass responsibility to the next validate
        return this->_next->validate(testString);
      }
      // reach the end of chain of responsibility
      return "Success";
    }
  };


  // Concrete handler
  class NotEmptyValidator : public BaseValidator {
  public:
    NotEmptyValidator() {};
    std::string validate(std::string testString) override {
      puts("Checking if empty...");

      if (testString.empty()) {
        return "Please enter a value";
      }
      return BaseValidator::validate(testString);
    };
  };

  
  // Concrete handler
  class LengthValidator : public BaseValidator {
  private:
    int _minLength;
  public:
    LengthValidator(int minLength) : _minLength(minLength) {};
    std::string validate(std::string testString) override {
      puts("Checking string length...");

      if ((int)testString.length() < _minLength) {
        return "Please enter a value longer " + 
          std::to_string(_minLength);
      }
      return BaseValidator::validate(testString);
    };
  };
  
  
  // Concrete handler
  class RegexValidator : public BaseValidator {
  private:
    std::string _patternName;
    std::string _regexString;
  public:
    RegexValidator(std::string patternName, std::string regexString) 
      : _patternName(patternName), _regexString(regexString) {};
    std::string validate(std::string testString) override {
      puts("Checking regex match...");
      if (!std::regex_match(testString, std::regex(_regexString))) {
        return "The value entered does not match the proper format for a " 
          + _patternName;
      }
      return BaseValidator::validate(testString);
    };
  };

  //bool in_array(const std::string& value, 
  //              const std::vector<std::string>& array) {
  //  return std::find(array.begin(), array.end(), value) != array.end();
  //};
  
  // Concrete handler
  class HistoryValidator : public BaseValidator {
  private:
    std::vector<std::string> _historyItems;
    
    bool in_array(const std::string& value, 
                  const std::vector<std::string>& array) {
    return std::find(array.begin(), array.end(), value) != array.end();
  };
  public:
    HistoryValidator(std::vector<std::string> historyItems) 
      : _historyItems(historyItems) {};
    std::string validate(std::string testString) override {
      puts("Checking if string has been used before...");
      if (in_array(testString, _historyItems)) {
        return "Please enter a value here that you haven't entered before ";
      }
      return BaseValidator::validate(testString);
    };
  };
  

};



/* structural design pattern */
namespace STRUCTURAL_DP {
  /* Proxy method */
  

  // Protective Proxy Type
  class Storage {
  public:
    virtual const string getContents() = 0;
    virtual ~Storage() = default;
  };


  class SecureStorage : public Storage {
  private:
    string _contents;
  public:
    explicit SecureStorage(const string& data) : _contents(data) {};
    const string getContents() {
      return _contents;
    }
  };

  const string SECRET_CODE = "1234";
  class SecureStorageProxy : public Storage {
  private:
    SecureStorage* _secureStorage;
    bool validateCode() {
      string input;
      cout << "Enter secret code: " << endl;
      cin >> input;
      return (input == SECRET_CODE);
    }
  public:
    SecureStorageProxy(const string& data) {
      _secureStorage = new SecureStorage(data);
       cout << "SecureStorageProxy created." << endl;
    };
    ~SecureStorageProxy() {
      delete _secureStorage;
    };

    const string getContents() {
      //string input;
      //cout << "Enter secret code: " << endl;
      //cin >> input;
      if (validateCode()) {
        cout << "Valid secret code...\n";
        return _secureStorage->getContents();
      } 
      cout << "Invalid secret code...\n";
      return "";
    }
  };

  // Virtual Proxy Type
  class ConfigFile {
  public:
    virtual vector<string> getSettings() = 0;
    virtual ~ConfigFile() = default;
  };


  // Concrete implementation of the ConfigFile
  class RealConfigFile : public ConfigFile {
  private:
    vector<string> _settings;
  public:
    explicit RealConfigFile(const string& filename) {
      cout << "RealConfigFile created." << endl;
      // Open file and read its contents into a vector of strings
      ifstream file(filename);
      string line;
      while (getline(file, line)) {
        _settings.push_back(line);
      }
      cout << _settings.size() << " settings loaded." << endl;
    };

    vector<string> getSettings() override {
      return _settings;
    }
  };


  class ConfigFileProxy : public ConfigFile {
  private:
    unique_ptr<RealConfigFile> _realConfigFile;
    string _filename;
  public:
    ConfigFileProxy(const string& filename) : 
      _realConfigFile(nullptr), _filename(filename) {
        cout << "ConfigFileProxy created." << endl;
      };
    // delegates the loading until getSettings is called
    vector<string> getSettings() override {
      // check if the pointer exist
      if (_realConfigFile == nullptr) {
        _realConfigFile = make_unique<RealConfigFile>(_filename);
      }
      return _realConfigFile->getSettings();
    }
  };

  /* Flyweight method implements
   * Flywheel objects, set by Factory, with common data or
   * intrinsic shared state while holding 
   * object-specific data, set by Client, in each flywheel object */
  class Texture {
  private:
    const string _fileName;
    int _id;
  public:
    explicit Texture(const string& fileName) : 
      _fileName(fileName), _id() {
        std::random_device rd; // random number generator object
        std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number engine
        std::uniform_int_distribution<> distrib(0, INT_MAX);
        _id = distrib(gen);
      };
    const string description() const {
      return ("<" + _fileName + " id " + to_string(_id) + ">");
    }
  };


  class Sprite {
  private:
    //object-specific extrinsic properties
    int _width;
    int _height;
    int _x;
    int _y; 
    
    /* common instrinsic properties*/
    const Texture* _texture;
  public:
    /*
    Sprite(const int& width, const int& height, 
           const int& x, const int& y, 
           const string& textureFileName) :
      _width(width), _height(height), _x(x), _y(y),
      _texture(new Texture(textureFileName)) {};
    */
    Sprite(const Texture* texture) : 
      _texture(texture) {
      cout << "Creating sprite with texture file: "
           << _texture->description() << endl;
    };
    void setPositionSize(const int& width, const int& height,
                         const int& x, const int& y) {
      _x = x;
      _y = y;
      _width = width;
      _height = height;
    };
    void render() const {
      cout << "Rendering sprite with texture: "
           << _texture->description() << endl;
    };
  };

  // class for client to retrive Sprite
  class SpriteFactory {
  private:
    unordered_map<string, Sprite*> _spritePool;
    unordered_map<string, Texture*> _texturePool;
    
    const Texture* getTexture(const string& fileName) {
      auto it = _texturePool.find(fileName);
      if (it != _texturePool.end()) {
        return it->second;
      } else {
       auto [newIt, _] = _texturePool.emplace(fileName, 
           new Texture(fileName));
       return newIt->second;
      } 
    };
  public:
    ~SpriteFactory() {
      for (auto& [filename, sprite] : _spritePool) {
        delete sprite;
      }
      for (auto& [filename, texture] : _texturePool) {
        delete texture;
      }
    };
    Sprite* makeSprite(const string& fileName) {
      auto it = _spritePool.find(fileName);
      if (it != _spritePool.end()) {
        return it->second;
      } else {
        const auto texture = getTexture(fileName);
        auto [newIt,_] = _spritePool.emplace(fileName, 
            new Sprite(texture));
        return newIt->second;
      }    
    }; 
  };


  /* Facade method implements
   * 1.) a Facade class as interface
   * 2.) underlying subsystem classes */
  class Database {
  public:
    void storeReservation(const string& reservation) {
      cout << "Database: Storing reservation " 
           << reservation << endl;
    }
  };
  
  
  class PaymentGateway {
  public:
    void processPayment(const string& paymentInfo) {
      cout << "Payment Gateway: Processing payment with info: " 
           << paymentInfo << endl;
    }
  };
  
  
  class MessagingService {
  public:
    void sendConfirmation(const string& message) {
      cout << "Messaging Service: Sending confirmation message: " 
           << message << endl;
    }
  };


  class ReservationSystemFacade {
  private:
    Database _database;
    PaymentGateway _paymentGateway;
    MessagingService _messagingService;
  protected:
  public:
    ReservationSystemFacade() : 
      _database(), _paymentGateway(), _messagingService() {};
    void makeReservation(const string& reservationInfo,
                        const string& paymentInfo,
                        const string& message="Reservation confirmed") {
      cout << "Running facade interface...\n";
      _database.storeReservation(reservationInfo);
      _paymentGateway.processPayment(paymentInfo);
      _messagingService.sendConfirmation(message);
    };

  };
  
  /* Decorator method extend
   * the functionality of an object
   * with no change to the original object */
  class Computer {
  public:
    virtual ~Computer() = default;
    virtual string description() const = 0;
    virtual double price() const = 0;
  };


  class Desktop : public Computer {
  public:
    string description() const override {
      return "Desktop";
    }
    double price() const override {
      return 1000.0;
    }
  };
  

  class Laptop : public Computer {
  public:
    string description() const override {
      return "Laptop";
    }
    double price() const override {
      return 1500.0;
    }
  };


  class ComputerDecorator : public Computer {
  protected:
    const Computer* _computer;
  public:
    explicit ComputerDecorator(const Computer* computer) : 
      _computer(computer) {};

    string description() const override {
      return _computer->description();
    };

    double price() const override {
      return _computer->price();
    };
  };
  
  
  class MemoryUpgradeDecorator : public ComputerDecorator {
  public:
    explicit MemoryUpgradeDecorator(const Computer* computer) : 
      ComputerDecorator(computer) {};

    string description() const override {
      return ComputerDecorator::description() + "with memory upgrade";
    };

    double price() const override {
      return ComputerDecorator::price() + 500.0;
    };
  };
  
  
  class GraphicsUpgradeDecorator : public ComputerDecorator {
  public:
    explicit GraphicsUpgradeDecorator(const Computer* computer) : 
      ComputerDecorator(computer) {};

    string description() const override {
      return ComputerDecorator::description() + "with graphics upgrade";
    };

    double price() const override {
      return ComputerDecorator::price() + 500.0;
    };
  };

  /* Composite method includes
   * 1.) Composite objects, e.g., class Box
   * 2.) Leaf objects, e.g., class Book and class Toy
   * using common or unified interface to simplify operations*/
   // unified interface
   class Product {
   public:
     virtual ~Product() = default; // dtor
     virtual double price() const = 0;
   };


   // class for leaf objects 
   class Book : public Product {
   private:
     std::string _title;
     double _price;
   public:
     Book(const std::string& title, const double& price) : 
       _title(title), _price(price) {}; // ctor
     double price() const override {
       cout << "Getting \"" << _title << "\" book price" << endl;
       return _price;
     }
   };
   
   
   // class for leaf objects 
   class Toy : public Product {
   private:
     std::string _name;
     double _priceTag;
   public:
     Toy(const std::string& name, const double& priceTag) : 
       _name(name), _priceTag(priceTag) {}; // ctor
     double price() const override {
       cout << "Getting \"" << _name << "\" toy price" << endl;
       return _priceTag;
     }
   };
   
   // class for composite objects 
   class Box : public Product {
   private:
     std::string _name;
     //std::vector<Book*> _books;
     //std::vector<Toy*> _toys;
     //std::vector<Box*> _boxes;
     std::vector<Product*> _products;
   
   public:
     explicit Box(const std::string& name) : _name(name) {};
     void addProduct(Product& product) { 
       _products.push_back( &product );
     };
     //void addBook(Book& book) { _books.push_back(&book); };
     //void addToy(Toy& toy) { _toys.push_back(&toy); };
     //void addBox(Box& box) { _boxes.push_back(&box); };
     double price() const override {
       cout << "Opening " << _name << endl;
       double totalPrice = 0;

       for (const auto& product : _products) {
         totalPrice+=(product->price());
       }
/*
       for (const auto& book : _books) {
         totalPrice+=(book->price());
       }
       
       for (const auto& toy : _toys) {
         totalPrice+=(toy->price());
       }
       
       for (const auto& box : _boxes) {
         totalPrice+=(box->price());
       }
*/
       return totalPrice;
     }
   };


  /* Bridge method separates
   * 1.) common features and
   * 2.) specific features 
   * in hierarchies */
  // Specific feature
  // Abstract class for message Preparation and Handling
  class ITextHandler {
  private:
  protected:
  public:
    virtual ~ITextHandler() = default;
    virtual std::string prepareMessage(const std::string& text) const = 0;
  };
  
  
  // Common feature
  // Abstract class for message Preparation and Handling
  class ITextSharer {
  private:
    const ITextHandler& _textHandler;
  protected:
    virtual bool sharePreparedText(const string& text) = 0;
  public:
    explicit ITextSharer(const ITextHandler& handler) :
      _textHandler(handler) {};
    virtual ~ITextSharer() = default;
    bool shareText(const std::string& text) {
      const std::string preparedText 
        = _textHandler.prepareMessage(text);
      return sharePreparedText(preparedText);
    };
  };
  
  
  // derived classes of ITextHandler
  class PlainTextHandler : public ITextHandler {
  private:
  protected:
  public:
    std::string prepareMessage(const std::string& text) const override {
      cout << "PlainTextHandler::prepareMessage() returning original text...\n"
           << endl;
      return text;
    };
  };
  
  
  class EncryptedTextHandler : public ITextHandler {
  private:
    std::string xorEncrypted(const std::string& input) const {
      char key = 64;
      std::string output = input;

      for (long unsigned int i = 0; i<input.size(); ++i) {
        output[i] = input[i] ^ key;
      }
      return output;
    };
  protected:
  public:
    std::string prepareMessage(const std::string& text) const override {
      cout << "EncryptedTextHandler::prepareMessage() encrypting text...\n"
           << endl;
      return xorEncrypted(text);
    };
  };
  
  class EmailShare : public ITextSharer {
  private:
  protected:
  public:
    explicit EmailShare(const PlainTextHandler& handler) : 
      ITextSharer(handler) {};
    bool sharePreparedText(const string& text) override {
      cout << "EmailShare::shareText() sharing text..." << text
           << endl;
      return true;
    };
  };
  
  
  class EmailShareEncrypted : public ITextSharer {
  private:
  protected:
  public:
    explicit EmailShareEncrypted(const EncryptedTextHandler& handler) : 
      ITextSharer(handler) {};
    bool sharePreparedText(const string& text) override {
      cout << "EmailShareEncrypted::shareText() sharing text..." << text
           << endl;
      return true;
    };
  };


  /* Adapter method has two ways of implementation 
   * 1. object adapter using composition 
   * 2. class adapter using inheritance */
  // base class
  class Component {
  protected:
  public:
   virtual void run() = 0; 
  };

  
  class ConcreteComponentA : public Component {
  protected:
  public:
   void run() override {
     cout << "Executing ConcreteComponentA::run()\n";
   }; 
  };
  
  
  class ConcreteComponentB : public Component {
  protected:
  public:
   void run() override {
     cout << "Executing ConcreteComponentB::run()\n";
   }; 
  };


  // legacy class
  class LegacyComponent {
  private:
  protected:
  public:
    void go() { cout << "Executing LegacyComponent::go()\n";};
  };


  // object adapter
  class LegacyAdapter : public Component {
  private:
    unique_ptr<LegacyComponent> _legacyComponent;
  protected:
  public:
    LegacyAdapter() : _legacyComponent(make_unique<LegacyComponent>()) {};
    void run() override {
      cout << "LegacyAdapter::run() -> calling LegacyComponent::go()\n";
      _legacyComponent->go();
    };
  }; 
  
  
  // class adapter
  class LegacyClassAdapter : public Component, private LegacyComponent {
  private:
  protected:
  public:
    LegacyClassAdapter() {};
    void run() override {
      cout << "LegacyClassAdapter::run() -> "
           << "calling LegacyComponent::go()\n";
      go();
    };
  }; 

}



/* creational design pattern */
namespace CREATIONAL_DP {

  // base class of factory 
  class Factory {
  private:
    std::string _name;
  public:
    Factory() {}; // ctor
  };


  /* factory method pattern using 
   * coffee machine and coffee.
   * */
  // base class as abstract class
  class Coffee {
  protected:
    char _type[20];
  public:
    Coffee() {}; // ctor
    ~Coffee() {}; // dtor
    char* getType(); 
  };


  // derived class as concrete class
  class Espresso : public Coffee {
  public:
    /* ctor */
    Espresso();
  };
 

  // derived class as concrete class 
  class Cappuccino : public Coffee {
  public:
    /* ctor */
    Cappuccino();
  };
 

  class CoffeeMakerFactory : public Factory {
  private:
  
  public:
    Coffee* getCoffee();
  }; 
  
   
  // base class as abstract class
  class Door {
  protected:
    std::string _name;
  public:
    /* ctor */
    Door() {};
    virtual void open() = 0;
  };
 

  // derived, concrete class as gas car door
  class GasCarDoor : public Door {
  public:
    GasCarDoor() : Door() { 
      _name = "Gas car door";
      printf("making a %s...\n", _name.c_str()); 
    }; // ctor
    void open() {cout << "gas door opens" << endl;};
  };


  // derived, concrete class as electric car door
  class ElectricCarDoor : public Door {
  public:
    ElectricCarDoor() : Door() {
      _name = "Electric car door";
      printf("making a %s...\n", _name.c_str()); 
      }; // ctor
    void open() {cout << "electric door opens" << endl;};
  };

  // base class as abstrct class
  class Powertrain {
  protected:
    std::string _name;
  public:
    /* ctor */
    Powertrain() {};
    virtual void start() = 0;
  };
 

  // derived, concrete class as engine
  class Engine : public Powertrain {
  public:
    Engine() : Powertrain() { 
      _name = "engine";
      printf("making a(n) %s...\n", _name.c_str()); 
    }; // ctor
    void start() { printf("%s starts\n", _name.c_str()); };
  };


  // derived, concrete class as door
  class Motor : public Powertrain {
  public:
    Motor() : Powertrain() { 
      _name = "Motor";
      printf("making a(n) %s...\n", _name.c_str()); 
      }; // ctor
    void start() { printf("%s starts\n", _name.c_str()); };
  };


  class Car {
  protected:
    string _name;
  };

  // base class for vehicle
  class CarMakerFactory : public Factory {
  protected:
    Car* _car;
  public:
    //vehicle* getVehicle();
    virtual Door* buildDoor() = 0;
    virtual Powertrain* buildPowertrain() = 0;
  };

  class GasCarMakerFactory : public CarMakerFactory {
  private:
  public:
    GasCarMakerFactory() {};// ctor
    Door* buildDoor() {return ( new GasCarDoor() );};
    Powertrain* buildPowertrain() { return (new Engine());};
  };
  
  
  class ElectricCarMakerFactory : public CarMakerFactory {
  private:
  public:
    ElectricCarMakerFactory() {};// ctor
    Door* buildDoor() {return ( new ElectricCarDoor() );};
    Powertrain* buildPowertrain() { return (new Motor());};
  };


  // base class of Entree
  class Entree {
  protected:
    std::string _name;
  public:
    Entree() {};
    string getName() {return _name;};
  };

  
  class Hamburger : public Entree {
  public:
    Hamburger() : Entree() {_name = "Hamburger";};
  };
  
  
  class Hotdog : public Entree {
  public:
    Hotdog() : Entree() {_name = "Hotdog";};
  };
  
  
  // base class of Side
  class Side {
  protected:
    std::string _name;
  public:
    Side() {};
    string getName() {return _name;};
  };

  
  class Fries : public Side{
  public:
    Fries() : Side() {_name = "Fries";};
  };
  
  
  class Salad : public Side {
  public:
    Salad() : Side() {_name = "Salad";};
  };

  
  class Drink {
  private:
    string _name;
  public:
    Drink() {_name = "Soda";};
    string getName() {return _name;};
  };


  // base class of builder
  class Meal {
  protected:
     string _name;
     Entree* _entree;
     Side* _side;
     Drink* _drink;
  public:
    Meal(string name):_name(name) {};
    void setEntree(Entree* e) {_entree = e;};
    void setSide(Side* s) {_side = s;};
    void setDrink(Drink* d) {_drink = d;};
    void showItems() {
      printf("\nMeal %s: %s, %s, and %s\n", _name.c_str(), 
                            _entree->getName().c_str(),
                            _side->getName().c_str(),
                            _drink->getName().c_str());
    };
  }; 
  
  
  class MealBuilder {
  protected:
     Meal* _Meal;
  public:
    virtual void cookEntree() = 0;
    virtual void cookSide() = 0;
    virtual void fillDrink() = 0;
    virtual Meal* getMeal() = 0;
  }; 
  
  
  class HamburgerMealBuilder : public MealBuilder {
  public:
    HamburgerMealBuilder() : MealBuilder() {
      _Meal = new Meal("Hamburger Meal");
    };
    void cookEntree() { 
      Hamburger* h = new Hamburger();
      printf("Cooking %s...\n", h->getName().c_str());
      _Meal->setEntree( h );
    };
    void cookSide() { 
      Fries* f = new Fries();
      printf("Cooking %s...\n", f->getName().c_str());
      _Meal->setSide( f );
    };
    void fillDrink() { 
      Drink* d = new Drink();
      printf("Filling %s...\n", d->getName().c_str());
      _Meal->setDrink( d );
    };
    Meal* getMeal() {return _Meal;};
  }; 
  
  
  class HotdogMealBuilder : public MealBuilder {
  public:
    HotdogMealBuilder() : MealBuilder() {
      _Meal = new Meal("Hotdog Meal");
    };
    void cookEntree() { 
      Hotdog* h = new Hotdog();
      printf("Cooking %s...\n", h->getName().c_str());
      _Meal->setEntree( h );
    };
    void cookSide() { 
      Salad* s = new Salad();
      printf("Preparing %s...\n", s->getName().c_str());
      _Meal->setSide( s );
    };
    void fillDrink() { 
      Drink* d = new Drink();
      printf("Filling %s...\n", d->getName().c_str());
      _Meal->setDrink( d );
    };
    Meal* getMeal() {return _Meal;};
  };


  // base class of Animal
  class Animal {
  protected:
    std::string _color;
    int _hairLength;
    int _tail;
    int _weight;
    int _height;
    int _age;

    int _intelligence;
    int _stubbornness;
    int _agressiveness;

  public:
    virtual Animal* clone() = 0;
    void setHariLength(const int& hl) {_hairLength = hl;};
    void setHariColor(const std::string& c) {_color = c;};
    void setTail(const int& t) {_tail = t;};       
    void setWeight(const int& w) {_weight = w;};                                      
    void setHeight(const int& h) {_height = h;};                                       
    void setAge(const int& a) {_age = a;};
    void printProperty() {
      DEBUG_MSG("_color: " << _color << std::endl);
      DEBUG_MSG("_hairLength: " << _hairLength << std::endl);
      DEBUG_MSG("_tail: " <<_tail << std::endl);
      DEBUG_MSG("_weight: " << _weight << std::endl);
      DEBUG_MSG("_height: " << _height << std::endl);
      DEBUG_MSG("_age: " << _age << std::endl);
      DEBUG_MSG("_intelligence: " << _intelligence << std::endl);
      DEBUG_MSG("_stubbornness: " << _stubbornness << std::endl);
      DEBUG_MSG("_agressiveness: " << _agressiveness << std::endl);
    };
  };


  class Sheep : public Animal {
  public:
    // ctor
    Sheep() {
      _hairLength = 5;
      _intelligence = 3;
      _stubbornness = 2;
      _agressiveness = 7;
    };

    Sheep* clone() { return new Sheep(*this); };
    void shearing(const int& d=2) { _hairLength -= d; };
  };
  
  
  class Cow : public Animal {
  public:
    // ctor
    Cow() {
      _hairLength = 9;
      _intelligence = 6;
      _stubbornness = 5;
      _agressiveness = 8;
    };

    Cow* clone() { return new Cow(*this); };
  };


  class Leader {
  private:
    static Leader* _instance;
    Leader() {cout << "A new leader is elected...\n";};
  public:
    static Leader* getInstance() {
      if (_instance == nullptr) {
        _instance = new Leader();
      }
      return _instance;
    };
    void giveSpeech() { cout << "Address the public\n";};
  };
 
}



namespace UTILITY_BINARY_OPERATION {
}



namespace DSA {


  /* SLink for singly linked list 
   * This class also serves a base class
   * for doubly linked list */ 
  template <typename T>
  struct SLink {
    T _value;
    SLink* _next;
    /* ctor */
    SLink(const T& value=0):_value(value), _next(nullptr) {
      //printf("Resource Acquisition Is Initialization.\n");
      //cout << "SLink of value: " << _value << endl;
    };
    /* dtor */
    ~SLink() {
      //printf("Deallocation...\n");
      //cout << "SLink of value: " << _value << endl;
    }
  };


  /* DLink for doubly link derived from SLink */
  template <typename T>
  struct DLink : public SLink<T> {
    DLink* _prev;
    
    /* ctor */
    DLink(const T& value): SLink<T>(value) {
      _prev = nullptr;
      printf("Resource Acquisition Is Initialization.\n");
      cout << "DLink of value: " << SLink<T>::_value << endl;
    };
    /* dtor */
    ~DLink() {
      printf("Deallocation...\n");
      cout << "DLink of value: " << SLink<T>::_value << endl;
    }
  };


  /* doubly linked list */
  template <typename T>
  class DLinkedList {
  private:
    DLink<T>* _head;
  
  public:
    /* ctor */
    DLinkedList():_head(nullptr) {
      printf("Resource Acquisition Is Initialization.\n");
      cout << "DLinkedList" << endl;
    };
    /* dtor */
    ~DLinkedList() {
      printf("Deallocation of linkedlist\n");
    };
    
    DLink<T>* searchLink(const T& value);
    void prependLink(const T& value);
    void insertLink(const T& newValue, const T& refValue);
    void deleteLink(const T& deletedValue);
    void showKeys();
  };
 

  template <typename T>
  DLink<T>* DLinkedList<T>::searchLink(const T& value) {
    if (this->_head == nullptr) {
      printf("Empty linked list\n");
      return nullptr;
    }
    
    /* assign _head ptr to tempLink*/
    DLink<T>* tempLink = this->_head;

    while (tempLink != nullptr) {
      /* check if link of key is found */
      if (tempLink->_value == value) {
        cout << "found link of key of " << value << endl;
        return tempLink; // found a link with key value
      }
      tempLink = static_cast<DLink<T>*>(tempLink->_next);
    }
    /* found no link matching key*/     
    cout << "No link matching key of " << value << endl; 
    return nullptr;
  };

  template <typename T>
  void DLinkedList<T>::prependLink(const T& value) {
    DLink<T>* tempLink = new DLink<T>(value);
    //cout << tempLink->_value << endl;

    /* update what pointer points */
    
    /* assign original value pointed by _head to tempLink->_next */
    tempLink->_next = this->_head;
    
    /* assign nullptr as head of list to tempLink->_prev */
    tempLink->_prev = nullptr; 

    /* assign tempLink to this->_head->_prev*/
    if (this->_head!=nullptr) {
      this->_head->_prev = tempLink;
    }

    /* assign new tempLink to what _head points */
    this->_head = tempLink; // head pointing to a new DLink
  };

  template <typename T>
  void DLinkedList<T>::insertLink(const T& newValue,
      const T& refValue) {
    /*search link of refValue*/
    DLink<T>* refLink = this->searchLink(refValue);

    /* link of value not found */
    if (refLink==nullptr) return;

    /* create a new link of newValue */
    DLink<T>* newLink = new DLink<T>(newValue);

    /* update the _next and _prev of nearby links 
     * newLink is connected next to refLink */
    
    /* assign refLink's next to newLink's next */
    newLink->_next = refLink->_next; 
    
    /* assign refLink's next's prev to newLink's prev */
    newLink->_prev = refLink; 
    
    /* assigne newLink to refLink's _next's _prev*/
    if (refLink->_next!=nullptr) { 
      static_cast<DLink<T>*>(refLink->_next)->_prev = 
        newLink;
    }
    /* assign newLink to refLink's next */
    refLink->_next = newLink;
  }
  
  template <typename T>
  void DLinkedList<T>::deleteLink(const T& deletedValue) {
    
    DLink<T>* deletedLink = this->searchLink(deletedValue);
    
    /* no link of deletedValue is found*/
    if (deletedLink == nullptr) return;
      
    //cout << static_cast<DLink<T>*>(deletedLink->_next)->_prev->_value << endl;
    cout << deletedLink->_value << endl;

    /* update _prev and _next of nearby links */

    /* assign deletedLink's _prev's _next to deletedLink's _next */
    if (deletedLink->_prev != nullptr) {
      deletedLink->_prev->_next = deletedLink->_next;
    } /*deletedLink->_prev is pointed by _head*/ else {
      this->_head = static_cast<DLink<T>*>(deletedLink->_next);
    }

    /* assign deletedLink's _next's _prev to deletedLink's _prev */
    if (deletedLink->_next != nullptr) {
      static_cast<DLink<T>*>(deletedLink->_next)->_prev = 
        deletedLink->_prev;
    }
    
    /* deallocate the memory of deletedLink */
    delete deletedLink;
  }

  template <typename T>
  void DLinkedList<T>::showKeys() {
    if (this->_head == nullptr) {
      printf("Empty linked list\n");
      return;
    }

    /* assign _head ptr to tempLink*/
    DLink<T>* tempLink = this->_head;

    while (tempLink != nullptr) {
      cout << tempLink->_value << " ";
      
      /* assign _next to tempLink */
      tempLink = static_cast<DLink<T>*>(tempLink->_next);
    }
    cout << endl;
  }


/* The template class and functions are defined in 
 * the same .h file. 
 * More advanded setting is needed to separate defintion 
 * to .cpp for template class and functions */
  template <typename T>
  class ArrayLikeDsAlg {
  public:
    /* ctor */
    ArrayLikeDsAlg() {};

    void bubbleSort(T arr[], const int& arrSize);
    void insertionSort(T arr[], const int& arrSize);
    void mergeSort(T arr[], const int& arrSize);

    void runMergeSort(T arr[], 
        const int& leftIndex, 
        const int& rightIndex);
    void merge(T arr[], 
        const int& leftIndex, 
        const int& midIndex,
        const int& rightIndex);
    
    void heapSort(T arr[], const int& arrSize);
    int parent(const int& curIndex) {return (curIndex>>1);};   
    int leftChild(const int& curIndex) {return (curIndex<<1);};   
    int rightChild(const int& curIndex) {return ((curIndex<<1)+1);};   
    void maxHeapify(T arr[], const int& curIndex, const int& arrSize);
    void buildMaxHeap(T arr[], const int& arrSize);

    void quickSort(T arr[], const int& arrSize);
    void runQuickSort(T arr[], 
        const int& leftIndex, 
        const int& rightIndex);
    int getPivotIndex(T arr[], 
        const int& leftIndex,
        const int& rightIndex);
    int getRandomizedNumber(const int& iniNum,
                            const int& endNum) {
      srand(time(NULL));
      auto randNum = [](int a, int b) {
        return (rand()%(b-a+1)+a);
      };
      
      return randNum(iniNum, endNum);
    };

    void countingSort();
    void radixSort();
    void bucketSort();

    void showArray(T arr[], const int& arrSize);
  };
  

  /* Bubble sort runs O(n^2) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::bubbleSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;
    
    for (auto i=0; i<arrSize-1; ++i) {
      for (auto j=i+1; j<arrSize; ++j) {
        if (arr[i] > arr[j]) swap(arr[i], arr[j]);
      }
    }
  };

  /* Insertion sort runs O(n^2) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::insertionSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;

    for (auto i=1; i<arrSize; ++i) {
      T key = arr[i];
      auto j = i-1; // iniital index j for arr[0:i-1]
      /* check if key is smaller than arr[j] */
      while (j>=0 and arr[j] > key) {
        /* move arr[j] to the arr[j+1] next to j, 
         * then j-- means moving to j-1 for next iteration
         * */
        arr[j+1] = arr[j];
        --j; 
      }
      /* set key to final position at j, which yields
       * a Sorted subarray A[0:i] */
      arr[++j]=key; 
    }
  };
  
  /* Merge sort runs O(nlog n) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::mergeSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;
      
    /* running merge sort algorithm */
    runMergeSort(arr, 0, arrSize-1);

  };
  
  /* helper function */
  template <typename T>
  void ArrayLikeDsAlg<T>::runMergeSort(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    /* Check index */
    if (leftIndex >= rightIndex) return;
      
    /* O(log n) time complexity
     * Divide and conquer recurrsively subarrays */
    int midIndex = leftIndex + 0.5*(rightIndex-leftIndex);
    runMergeSort(arr, leftIndex, midIndex);
    runMergeSort(arr, midIndex+1, rightIndex);

    /* O(n) time complexity
     * Merge the subarrays */
    merge(arr, leftIndex, midIndex, rightIndex);
  };
  
  
  /* helper function of merging subarrays */
  template <typename T>
  void ArrayLikeDsAlg<T>::merge(T arr[],
     const int& leftIndex,
     const int& midIndex,
     const int& rightIndex) {
    
    auto leftArrSize = midIndex-leftIndex+1;
    auto rightArrSize = rightIndex-midIndex;

    /* allocate memory for subarrays */
    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];
    
    /* assign left subarray */
    std::copy(arr+leftIndex, arr+midIndex+1, leftArr);
    
    /* assign right subarray */
    std::copy(arr+(midIndex+1), arr+rightIndex+1, rightArr);

    auto arrIndex = leftIndex; // index for filling original arr
    auto tempLeftIndex = 0;
    auto tempRightIndex = 0;
    while (tempLeftIndex < leftArrSize and 
           tempRightIndex < rightArrSize ) {
      /* compare smaller element from both subarrays*/
      if (leftArr[tempLeftIndex] < rightArr[tempRightIndex]) {
        arr[arrIndex++] = move(leftArr[tempLeftIndex++]);
      } else {
        arr[arrIndex++] = move(rightArr[tempRightIndex++]);
      }
    }

    /* fill any elements left in subarrays */
    if (tempLeftIndex < leftArrSize) {
      copy(leftArr+tempLeftIndex,
           leftArr+leftArrSize,
           arr+arrIndex); 
    } 
    if (tempRightIndex < (rightIndex-midIndex)) { 
      copy(rightArr+tempRightIndex,
           rightArr+rightArrSize,
           arr+arrIndex); 
    }
    
    /* deallocate memory pointed by ptr */
    delete[] leftArr;
    delete[] rightArr;
  };
  
  /* heap sort runs O(nlon n) time complexity i
   * O(n): buildMaxHeap
   * O(log n): maxHeapify */
  template <typename T>
  void ArrayLikeDsAlg<T>::heapSort(T arr[], const int& arrSize){
    /* converts an array arr[0:arrSize-1] into a max-heap */ 
    buildMaxHeap(arr, arrSize);
    
    /* In each iteration, moving root element (maximum at arr[0]) 
     * of arr[0:arrSize-1] to arr[arrSize-1], and then for next
     * iteration, heapify arr[0:arrSize-2] and move the next 
     * max or root to arr[arrSize-2] in recurrsive manner till 
     * arr[1] */
    for (auto i=arrSize-1; i>0; --i) {
      /* move root toward the end of heap*/
      swap(arr[0]/*root*/, arr[i]);
      
      /* heapify again for smaller arr[0:i]*/
      maxHeapify(arr, 0/*root index*/, i/*new heap size*/);
    }
  }

  /* O(n) time complexity 
   * helper function buildMaxHeap converts an array A[1 : n] or
   * arr[0:arrSize-1] into a max-heap by calling maxHeapify in 
   * a Bottom-Up manner.
   * 
   * Ouput: the maximum element of the array is stored at      
   * the root arr[0]
   *
   * A[ floor(n>>2)+1:n ] are leave nodes as 1-element heap
   * A[ 1:floor(n>>2) ] are internal nodes running maxHeapify
   * 
   * */
  template <typename T>  
  void ArrayLikeDsAlg<T>::buildMaxHeap(T arr[], 
      const int& arrSize /*size as one-based index*/) {
    
    for (auto i=(floor(arrSize>>1)-1)/*zero-based index*/; i>=0; --i ) {
      maxHeapify(arr, i, arrSize);
    }
  }

  /* O(log n) time complexity
   * helper function maintain max heap property
   * A[parent(index)]>=A[index] */  
  template <typename T>
  void ArrayLikeDsAlg<T>::maxHeapify(T arr[], 
      const int& curIndex,
      const int& arrSize) {
    //cout << arr[curIndex] << endl;
    
    /* indices is converted based on one-based index */
    //auto parentIndex = parent(curIndex+1) - 1;
    auto leftChildIndex = leftChild(curIndex+1) - 1;
    auto rightChildIndex = rightChild(curIndex+1) - 1;
    auto largestIndex = curIndex;

    /* check if
     * 1. left child index (one-based) within array/heap size 
     * 2. leftChild has larger value than curIndex */
    if ((leftChildIndex+1) <= arrSize and 
        arr[leftChildIndex] > arr[curIndex]) {
      largestIndex = leftChildIndex;
    } 
    
    /* check if 
     * 1. right child index (one-based) within array/heap size 
     * 2. rightChild has larger value than the updated 
     * largest value at largestIndex */
    if ((rightChildIndex+1) <= arrSize and 
        arr[rightChildIndex] > arr[largestIndex]) {
      largestIndex = rightChildIndex; 
    }

    /* check if the largest is not at curIndex */
    if (largestIndex!=curIndex) {
      
      /* swap the largest value with value at curIndex */
      swap(arr[curIndex], arr[largestIndex]);

      /* moving to the current largest index to heapify */
      maxHeapify(arr, largestIndex, arrSize);
    }
  }
   
  /* O(n^2) time complexity
   * quick sort has swap step in divide (partition) 
   * */ 
  template <typename T>
  void ArrayLikeDsAlg<T>::quickSort(T arr[], 
      const int& arrSize){
    runQuickSort(arr, 0, arrSize-1/*index*/);
  }
  
  template <typename T>
  void ArrayLikeDsAlg<T>::runQuickSort(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    
    if (leftIndex > rightIndex) return;

    /* get pivotIndex with 
     * elements arr[leftIndex: pivotIndex-1] <= arr[pivotIndex]
     * elements arr[pivotIndex+1:rightIndex] > arr[pivotIndex]*/
    int pivotIndex = getPivotIndex(arr, leftIndex, rightIndex);
    
    /* subarray Left to pivotIndex */
    runQuickSort(arr, leftIndex, pivotIndex-1);
    
    /* subarray Right to pivotIndex */
    runQuickSort(arr, pivotIndex+1, rightIndex);
  } 

  template <typename T>
  int ArrayLikeDsAlg<T>::getPivotIndex(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    /* Set initial  pivot index */
    // randomization
    auto j = getRandomizedNumber(leftIndex, rightIndex); // rightIndex may be changed 
    swap(arr[j], arr[rightIndex]);
    
    auto pivotIndex = rightIndex; // rightIndex may be changed 
    auto pivotLeft = leftIndex-1; // index left to pivot

    /* browse elements in arr[0:r-1] */
    for (auto i=leftIndex; i<rightIndex; ++i) {
      
      /* element smaller than pivot */
      if (arr[i]<=arr[pivotIndex]) {
        /*move smaller element right to pivotLeft*/
        swap(arr[i], arr[++pivotLeft]);
      }
    }

    /* move pivot to arr[pivotLeft+1] */
    swap(arr[pivotLeft+1], arr[pivotIndex]);
    return (pivotLeft+1); 
  }
    
  /* Show array elements */ 
  template <typename T>
  void ArrayLikeDsAlg<T>::showArray(T arr[], const int& arrSize) {
    for (auto i=0; i<arrSize; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }

  /* class Stack is LIFO data structure 
   * inheriting from vector class */
  template <typename T>
  class Stack : public vector<T> {
  public:
    /* ctor */
    Stack():_topIndex(-1), _vec(new vector<T>) {};
    ~Stack() {delete[] _vec;};
    void push(const T& value);
    void pop();
    T getTop();
    bool isEmpty();

  private:
   int _topIndex;
   vector<T>* _vec;
  };

  
  /* push a value, incrementing _topIndex, 
   * at the top of stack */
  template <typename T>
  void Stack<T>::push(const T& value) {
    ++_topIndex;
    //cout << "element " << value 
    //     << " is pushed at _topIndex " << (_topIndex) << endl;
    this->_vec->push_back(value);
  }
  
  /* pop a value from top of a stack, then decrementing _topIndex */
  template <typename T>
  void Stack<T>::pop() {
    /* pop only if stack is Not empty */
    if (!isEmpty()) {
     this-> _vec->pop_back();
      --_topIndex;
      return;
    }
    cout << "Empty stack! No element to pop...\n";
  }
  
  /* pop a value from top of a stack, then decrementing _topIndex */
  template <typename T>
  T Stack<T>::getTop() {
    /* getTop only if stack is Not empty */
    if (!isEmpty()) return (this->_vec->at(_topIndex));
    
    cout << "Empty stack! No element at top\n";
    exit(-1);
  }
  
  /* check if stack is empty */
  template <typename T>
  bool Stack<T>::isEmpty() {
    return ((_topIndex>-1)?false:true);
  }

  
  /* class Stack: implementation of LIFO data structure */
  template <typename T>
  class BrowseHistory  {
  public:
    BrowseHistory() : _urlHistoryStackPtr(new Stack<T>) {};
    void visit(const T& url) {_urlHistoryStackPtr->push(url);};
    void back() {_urlHistoryStackPtr->pop();};
    T current() const {
      if (_urlHistoryStackPtr->isEmpty() ) {
        cout << "No sites currently being viewed!\n";
        exit(-1);
      }
      return _urlHistoryStackPtr->getTop();
    };
  
  private:
    std::string _url;
    Stack<T>* _urlHistoryStackPtr;
  };

 
  /* class Queue: implementation of FIFO data structure */
  template <typename T>
  class Queue {
  private:
    int _headIndex;
    int _tailIndex;
    int _size;
    int _capacity;
    std::vector<T>* _vecPtr;

  public:
    /* ctor of one arg */
    Queue(const int& capacity=12): 
      _headIndex(0), _tailIndex(0), _size(0), _capacity(capacity),
      _vecPtr(new vector<T>(capacity)) {};
    
    bool isFull() {
      if (_size == _capacity) {
        return true;
      }
      return false;
    };

    bool isEmpty() {return ((_size==0)?true:false);};

    void enqueue(const T& value) {
      if (isFull()) {
        cout << "Queue is full\n";
        return;
      }
      _vecPtr->at(_tailIndex++)=value;
      cout << "value: " << value << " at " << _tailIndex-1 << endl;
      _tailIndex%=_capacity;
      ++_size;
      //cout << "_size: " << _size << endl;
    };
    
    T dequeue() {
      T dequeuedValue = _vecPtr->at(_headIndex++);
      _headIndex%=_capacity;
      --_size;
      cout << "_size: " << _size << endl;
      return dequeuedValue;
    };

    T getFront() {return _vecPtr->at(_headIndex);};
    
  };


  /* Priority Queue */
  template <typename T>
  struct TaskKey {
    std::string _task;
    T _key;
    /* ctor */
    TaskKey() {}; 
    TaskKey(const std::string& task, const T& key):_task(task), _key(key) {};
  };

  template <typename T>
  class PriorityQueue:public Queue<T> {
  public:
    PriorityQueue(const T& taskKey): _taskKey(taskKey) {};
    void insert(const T& taskKey);
    T getMaximum();
    void extractMaximum();
    void increaseMaximum();
  private:
    T  _taskKey;
  };

  
  template <typename T>
  T PriorityQueue<T>::getMaximum() {
    return _taskKey;
  }

  template <typename T>
  void PriorityQueue<T>::insert(const T& taskKey) {
    //Queue<T>::enqueue(taskKey);
  }


  /* A Node for Binary Search Tree
   * has attributes Parent, leftChild, and rightChild
   * */
  template <typename T>
  struct Node {
  T _key; // value store in a Node
  Node* _parent; // parent node pointer
  Node* _leftChild; // left-child node pointer
  Node* _rightChild; // right-child node pointer
  /* ctor */
  Node():_parent(nullptr), 
         _leftChild(nullptr), 
         _rightChild(nullptr) 
    { printf("RAII: a node is created\n"); };
  Node(const T& key):_key(key), 
                     _parent(nullptr), 
                     _leftChild(nullptr), 
                     _rightChild(nullptr) 
    { cout << "RAII: a node of key "
                                      << _key
                                      << " is allocated.\n"; };
  /* dtor */
  ~Node() { cout << "RAII: a node of key "
                 << _key
                 << " is de-allocated.\n"; };
  };


  /* Binary Search Tree (BST)
   * is a Organized data strcture
   *
   * binary-search-tree property:
   * Let x be a node in a binary search tree. 
   * If y is a node in the left subtree of x, then y.key ≤ x.key. 
   * If y is a node in the right, subtree of x, then y.key ≥ x.key.
   * */
  template <typename T>
  class BinarySearchTree {
  public:
    /* ctor */
    BinarySearchTree():_root(nullptr) {
      printf("RAII: a binary search tree is allocated\n");
    };
    BinarySearchTree(Node<T>* nodePtr):_root(nodePtr) {
      cout << "RAII: a binary search tree of root with key "
           << nodePtr->_key
           << " is allocated\n";
      _root->_parent = nullptr; // root's parent is nullptr
    };
    ~BinarySearchTree() {
      cout << "RAII: a binary search tree of root with key "
           << this->_root->_key
           << " is de-allocated\n"; 
      //delete _root;
    };
    void runInOrderTreeWalk() const;
    void runPreOrderTreeWalk() const;
    void runPostOrderTreeWalk() const;
    void inOrderTreeWalk(const Node<T>* node) const;
    void preOrderTreeWalk(const Node<T>* node) const;
    void postOrderTreeWalk(const Node<T>* node) const;
    void treeInsert(Node<T>* node);
    void treeDelete(Node<T>* node);
    void relocate(
        Node<T>* deletedNode, Node<T>* substituteNode);
    
    const Node<T>* iterativeTreeSearch(const Node<T>* node) const; 
    Node<T>* getMaximum() const; 
    Node<T>* maximum(Node<T>* aRoot) const; 
    Node<T>* getMinimum() const; 
    Node<T>* minimum(Node<T>* aRoot) const; 
    Node<T>* getSuccessor(Node<T>* node) const; 
    Node<T>* getPredecessor(Node<T>* node) const; 
  
  private:
    Node<T>* _root; // root node pointer of BST

  };

  
  template <typename T>
  void BinarySearchTree<T>::runInOrderTreeWalk() const {
    inOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::runPreOrderTreeWalk() const {
    preOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::runPostOrderTreeWalk() const {
    postOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::inOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      inOrderTreeWalk(node->_leftChild);
      cout << node->_key << " ";
      inOrderTreeWalk(node->_rightChild);
    }
  };
  
  template <typename T>
  void BinarySearchTree<T>::preOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      cout << node->_key << " ";
      preOrderTreeWalk(node->_leftChild);
      preOrderTreeWalk(node->_rightChild);
    }
  };
  
  template <typename T>
  void BinarySearchTree<T>::postOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      postOrderTreeWalk(node->_leftChild);
      postOrderTreeWalk(node->_rightChild);
      cout << node->_key << " ";
    }
  };

  template <typename T>
  void BinarySearchTree<T>::treeInsert(Node<T>* node) {
    Node<T>* curNode = _root;
    Node<T>* curParent = nullptr;
    
    /* descend from _root node*/
    while (curNode!=nullptr) {
      curParent = curNode; // curNode become new curParent
      
      /* check node's key with curNode's key*/
      if (node->_key < curNode->_key) {
        curNode = curNode->_leftChild;
      } else {
        curNode = curNode->_rightChild;
      }
    }

    /* node's parent is updated */
    node->_parent = curParent;
    
    if (curParent == nullptr) {
      _root = node;
    } else if (node->_key < curParent->_key) {
      curParent->_leftChild = node;
    } else {
      curParent->_rightChild = node;
    }
  };

  /*
   * 3 cases
   * 1. if curNode has No children, remove curNode simply
   * 2. if curNode has one child, elevate that child to 
   * take the position of curNode
   * 3. curNode has two children -> rightChild as the 
   * successor of curNode or -> successor of curNode
   * is at the right subtree*/
  template <typename T> 
  void BinarySearchTree<T>::treeDelete(Node<T>* node) {
    cout << "deleting node of " << node->_key << endl;
    
    // case 1. and case 2.
    // node's rightChild as nullptr
    if (node->_rightChild==nullptr) {
      this->relocate(node, node->_leftChild);
    } 
    // node's leftChild as nullptr
    else if (node->_leftChild==nullptr) {
      this->relocate(node, node->_rightChild);
    }
    // case 3.
    else if (Node<T>* successorNode=this->getSuccessor(node)) {
      // succeesor of node is Not its_rightChild
      if (successorNode!=node->_rightChild) {
      
        // frist, successor's Right Subtree takes its position
        relocate(successorNode, successorNode->_rightChild);
      
        // second, successor takes node's rightChild position 
        successorNode->_rightChild = node->_rightChild;
        successorNode->_rightChild->_parent = successorNode;
      }
      
      // relocate node's current _rightChild to node's position
      relocate(node, successorNode);
      
      // update successorNode's leftChild as node's leftChild
      successorNode->_leftChild = node->_leftChild;
      successorNode->_leftChild->_parent = successorNode;
    }

  };
  
  /* replaces one subtree as a child of its parent with 
   * another subtree*/ 
  template <typename T> 
  void BinarySearchTree<T>::relocate(
      Node<T>* replacedNode, Node<T>* substituteNode
      ) {
    cout << "Node of " << replacedNode->_key << " is " 
         << "replaced..." << endl; 
    // replacedNode as _root
    if (replacedNode->_parent==nullptr) {
      printf("root is replaced\n");
      this->_root = substituteNode;
    } 
    // replacedNode as _leftChild of a node 
    else if (replacedNode->_parent->_leftChild==replacedNode) {
      replacedNode->_parent->_leftChild = substituteNode;
    } 
    // replacedNode as _rightChild of a node 
    else if (replacedNode->_parent->_rightChild==replacedNode) {
      replacedNode->_parent->_rightChild = substituteNode;
    }

    // updated substituteNode's parent as replacedNode's parent
    // if it is non null node
    if (substituteNode != nullptr) {
      substituteNode->_parent = replacedNode->_parent;
    }
  };

  /* O(h) time complexity 
   * h is the height of the tree */
  template <typename T>
  const Node<T>* BinarySearchTree<T>::iterativeTreeSearch(
      const Node<T>* node) const {
    // start from _root
    Node<T>* curNode = _root; 
    
    while (curNode!=nullptr) {
      // check if the value is found in curNode 
      if (node->_key == curNode->_key) {
        return node; // found a node
      } // move down to left subtree
      else if (node->_key < curNode->_key) {
        curNode = curNode->_leftChild; 
      } // move down to right subtree
      else {
        curNode = curNode->_rightChild; 
      }
    }
    return nullptr; // found no matching node 
  }; 
  
  template <typename T>  
  Node<T>* BinarySearchTree<T>::getMaximum() const {
    return maximum(this->_root);
  }; 
 
  /* O(h) time complexity */ 
  template <typename T>
  Node<T>* BinarySearchTree<T>::maximum(
      Node<T>* aRoot) const {
    Node<T>* tempNode = aRoot;
    
    while (tempNode->_rightChild!=nullptr) {
      tempNode=tempNode->_rightChild;
    }
    return tempNode;
  };

  template <typename T>
  Node<T>* BinarySearchTree<T>::getMinimum() const {
    return minimum(this->_root);
  };

  template <typename T>
  Node<T>* BinarySearchTree<T>::minimum(
      Node<T>* aRoot) const {
    Node<T>* tempNode = aRoot;
    while (tempNode->_leftChild!=nullptr) {
      tempNode=tempNode->_leftChild;
    }
    return tempNode;
  }; 
    
  template <typename T>
  Node<T>* BinarySearchTree<T>::getSuccessor(
      Node<T>* node) const {
    if (node->_rightChild) {
      return minimum(node->_rightChild);  
    } else {
      Node<T>* tempNode=node->_parent;
      while (tempNode!=nullptr and node==tempNode->_rightChild) {
        node = tempNode;
        tempNode = tempNode->_parent;
      }
      return tempNode;
    }
    return nullptr;
  }; 
  
  template <typename T>
  Node<T>* BinarySearchTree<T>::getPredecessor(
      Node<T>* node) const {
    if (node->_leftChild) {
      return maximum(node->_leftChild);  
    } else {
      Node<T>* tempNode=node->_parent;
      while (tempNode!=nullptr and node==tempNode->_leftChild) {
        node = tempNode;
        tempNode = tempNode->_parent;
      }
      return tempNode;
    }
    return nullptr;
  }; 


  /*
   * Red-Black Node
   * strct RBNode is derived from struct Node
   * */
  enum class Color {Red=0, Black};

  template <typename T>
  struct RBNode {
    T _key; // value store in a RBNode
    RBNode* _parent; // parent RBNode pointer
    RBNode* _leftChild; // left-child RBNode pointer
    RBNode* _rightChild; // right-child RBNode pointer
    std::string _color;
    Color _enumColor;
    
    /* ctor */
    RBNode();
    RBNode(const T& key, const std::string& color);
    RBNode(const T& key, const Color& enumColor);

    /* dtor */
    ~RBNode() {
      cout << "RAII, de-allocation of RBNode (key, color) = " 
           << "(" << _key << "," 
           << _color << ")\n"; 
    };
  };

  template<typename T> 
  RBNode<T>* nil = new RBNode<T>();

  template <typename T> 
  void initNilNode() {
    nil<T>->_enumColor = Color::Black;
    nil<T>->_leftChild 
      = nil<T>->_rightChild 
      = nil<T>->_parent 
      = nil<T>;
  };
    
  /* ctors of struct RBNode */
  template <typename T>
  RBNode<T>::RBNode():_parent(nullptr), 
                   _leftChild(nullptr), 
                   _rightChild(nullptr),
                   _enumColor(Color::Black) {
 
    //cout << "RAII, allocation of RBNode of " 
    //     << "nullptr\n";
  }
    
  template <typename T>
  RBNode<T>::RBNode(const T& key, const std::string& color) 
      : _key(key),
        _parent(nil<T>),     
        _leftChild(nil<T>),
        _rightChild(nil<T>),
        _color(color), 
        _enumColor(color=="Red"?Color::Red:Color::Black) {
    cout << "RAII, allocation of RBNode (key, color) = "
         << "(" << _key << "," 
         << (_enumColor==Color::Red?"Red":"Black") << ")\n";
  }
    
  template <typename T>
  RBNode<T>::RBNode(const T& key, const Color& enumColor) 
      : _key(key), 
        _parent(nil<T>),     
        _leftChild(nil<T>),
        _rightChild(nil<T>),
        _color(enumColor==Color::Red?"Red":"Black"), 
        _enumColor(enumColor) {
    initNilNode<T>();
    cout << "RAII, allocation of RBNode (key, color) = " 
         << "(" << _key << "," 
         << _color << ")\n"; 
  };


  /*
   * Red-Black Binary Search Tree (RBBst)
   * the RBBst is approximately balanced
   * satisﬁes the following red-black properties:
   *  1. Every node is either red or black.
   *  2. The root is black.
   *  3. Every leaf (NIL) is black.
   *  4. If a node is red, then both its children are black.
   *  5. For each node, all simple paths from the node to 
   *  descendant leaves contain the same number of black nodes.
   * */
  template <typename T>
  class RBBinarySearchTree /*: BinarySearchTree<T>*/ {
  private:
    //RBNode<T>* _nil;
    RBNode<T>* _root;
  public:
    /* ctors */
    RBBinarySearchTree():_root(nil<T>) {
      initNilNode<T>();
      cout << "RAII, allocation of RBBst with root of " 
           << "nullptr\n"; 
    }; 
    RBBinarySearchTree(const T& key) : 
      _root( new RBNode<T>(key, Color::Black) ) {
      cout << "RAII, allocation of RBBst with root of (key, color) = " 
           << "(" << _root->_key << "," 
           << _root->_color << ")\n"; 
    };
    /* dtor */
    ~RBBinarySearchTree() {
      cout << "RAII, de-allocation of RBBst with root of (key, color) = " 
           << "(" << _root->_key << "," 
           << _root->_color << ")\n";
      postOrderTreeDelete(_root);
    }; 
  
    void inOrderTreeWalk(RBNode<T>* node);
    void inOrderTreeWalkRoot();
    void leftRotation(RBNode<T>* pivotNode);
    void rightRotation(RBNode<T>* pivotNode);
    void rbInsert(RBNode<T>* curNode);
    void rbInsertFixup(RBNode<T>* curNode);
    void showKeyColor(RBNode<T>* node) const;
    void postOrderTreeDelete(const RBNode<T>* curNode);
    void rbRelocate(RBNode<T>* oldNode, RBNode<T>* newNode);
    void rbDelete(RBNode<T>* deletedNode);
    void rbDeleteFixup(RBNode<T>* Node);
    RBNode<T>* treeMinimum(RBNode<T>* node);
    RBNode<T>* getMinimum();
    RBNode<T>* treeMaximum(RBNode<T>* node);
    RBNode<T>* getMaximum();
  };
   

  template <typename T>
  void RBBinarySearchTree<T>::rbDeleteFixup(RBNode<T>* Node) {
    while (  (Node != (this->_root)) && 
            ((Node->_enumColor)==Color::Black) ) {
      // check Node as leftChild
      if (Node == Node->_parent->_leftChild) {
        RBNode<T>* sibling = Node->_parent->_rightChild;

        if ((sibling->_enumColor) == Color::Red) {
          sibling->_enumColor = Color::Black;
          Node->_parent->_enumColor = Color::Red;
          leftRotation(Node->_parent);
          sibling = Node->_parent->_rightChild;
        }

        if ((sibling->_leftChild->_enumColor) == Color::Black &&
            (sibling->_rightChild->_enumColor) == Color::Black) {
          sibling->_enumColor = Color::Red;
          Node = Node->_parent; 
        } else {
          
          if (sibling->_rightChild->_enumColor == Color::Black) {
            sibling->_leftChild->_enumColor = Color::Black;
            sibling->_enumColor = Color::Red;
            rightRotation(sibling);
            sibling = Node->_parent->_rightChild;
          }
          sibling->_enumColor = Node->_parent->_enumColor;
          Node->_parent->_enumColor = Color::Black;
          sibling->_rightChild->_enumColor = Color::Black;
          leftRotation(Node->_parent);
          Node = this->_root;
        }
      }
      else {
        RBNode<T>* sibling = Node->_parent->_leftChild;

        if ((sibling->_enumColor) == Color::Red) {
          sibling->_enumColor = Color::Black;
          Node->_parent->_enumColor = Color::Red;
          rightRotation(Node->_parent);
          sibling = Node->_parent->_leftChild;
        }

        if ((sibling->_rightChild->_enumColor) == Color::Black &&
            (sibling->_leftChild->_enumColor) == Color::Black) {
          sibling->_enumColor = Color::Red;
          Node = Node->_parent; 
        } else {
          
          if (sibling->_leftChild->_enumColor == Color::Black) {
            sibling->_rightChild->_enumColor = Color::Black;
            sibling->_enumColor = Color::Red;
            leftRotation(sibling);
            sibling = Node->_parent->_leftChild;
          }
          sibling->_enumColor = Node->_parent->_enumColor;
          Node->_parent->_enumColor = Color::Black;
          sibling->_leftChild->_enumColor = Color::Black;
          rightRotation(Node->_parent);
          Node = this->_root;
        }
      }
    }
    Node->_enumColor = Color::Black;
  };

  template <typename T>
  RBNode<T>* RBBinarySearchTree<T>::getMinimum() {
    return treeMinimum(this->_root);
  };
  
  template <typename T>
  RBNode<T>* RBBinarySearchTree<T>::getMaximum() {
    return treeMaximum(this->_root);
  };

  template <typename T>
  RBNode<T>* RBBinarySearchTree<T>::treeMinimum(
      RBNode<T>* node) {
    while (node->_leftChild != nil<T>) {
      node = node->_leftChild;
    }
    return node;
  };
  
  template <typename T>
  RBNode<T>* RBBinarySearchTree<T>::treeMaximum(
      RBNode<T>* node) {
    while (node->_rightChild != nil<T>) {
      node = node->_rightChild;
    }
    return node;
  };
  
  template <typename T>
  void RBBinarySearchTree<T>::rbDelete(
      RBNode<T>* deletedNode) {
    RBNode<T>* tempNode = deletedNode;
    Color tempNodeColor = tempNode->_enumColor;
    RBNode<T>* tempChild;
    
    if (deletedNode->_leftChild == nil<T>) {
      tempChild = deletedNode->_rightChild;
      rbRelocate(deletedNode,
                 deletedNode->_rightChild);
    } else if (deletedNode->_rightChild == nil<T>) {
      tempChild = deletedNode->_leftChild;
      rbRelocate(deletedNode,
                 deletedNode->_leftChild);
    } else { 
        tempNode = treeMinimum(deletedNode->_rightChild);
        tempNodeColor = tempNode->_enumColor;
        tempChild = tempNode->_rightChild;

        if (tempNode != deletedNode->_rightChild) {
          rbRelocate(tempNode,
                     tempNode->_rightChild);
          tempNode->_rightChild = deletedNode->_rightChild;
          tempNode->_rightChild->_parent = tempNode;
        } else {
          tempChild->_parent = tempNode;
        }
         
        rbRelocate(deletedNode, tempNode);
        tempNode->_leftChild = deletedNode->_leftChild;
        tempNode->_leftChild->_parent = tempNode;
        tempNode->_enumColor = deletedNode->_enumColor;
    }

    if (tempNodeColor == Color::Black) {
      rbDeleteFixup(tempChild);
    }
  };
    
  template <typename T>
  void RBBinarySearchTree<T>::rbRelocate(RBNode<T>* oldNode, 
                                         RBNode<T>* newNode) {
    // oldNode as root node
    if (oldNode->_parent == nil<T>) {
      this->_root = newNode;
    } 
    // oldNode as a leftChild
    else if ( oldNode == (oldNode->_parent->_leftChild) ) {
      oldNode->_parent->_leftChild = newNode;
    } 
    // oldNode as a rightChlild
    else if ( oldNode == (oldNode->_parent->_rightChild) ) {
      oldNode->_parent->_rightChild = newNode;
    }

    // update newNode's parent
    newNode->_parent = oldNode->_parent;
  };

  template <typename T>
  void RBBinarySearchTree<T>::showKeyColor(RBNode<T>* node) 
  const {
    cout << "(" << node->_key << ","
         << (node->_enumColor==Color::Red?"Red":"Black")
         << ")" << endl; 
  }

  template <typename T>
  void RBBinarySearchTree<T>::postOrderTreeDelete(
      const RBNode<T>* curNode) {
    if (curNode != nil<T>) {
      postOrderTreeDelete(curNode->_leftChild);
      postOrderTreeDelete(curNode->_rightChild);
      delete curNode;
    }
  };
  
  template <typename T>
  void RBBinarySearchTree<T>::inOrderTreeWalkRoot() {
    RBNode<T>* node = this->_root;
    if (node != nil<T>) {              
      inOrderTreeWalk(static_cast<RBNode<T>*>(node->_leftChild));                        
      cout << "root-";
      showKeyColor(node);                                
      inOrderTreeWalk(static_cast<RBNode<T>*>(node->_rightChild));                       
    }                                                           
  };
  
  template <typename T>
  void RBBinarySearchTree<T>::inOrderTreeWalk(RBNode<T>* node) {      
    if (node != nil<T>) {              
      inOrderTreeWalk(static_cast<RBNode<T>*>(node->_leftChild));                        
      showKeyColor(node);                                
      inOrderTreeWalk(static_cast<RBNode<T>*>(node->_rightChild));                       
    }                                                           
  };

  template <typename T>
  void RBBinarySearchTree<T>::leftRotation(RBNode<T>* pivotNode) {
    RBNode<T>* tempRightChild 
      = static_cast<RBNode<T>*>(pivotNode->_rightChild);
    
    /* turn tempRightChild's LEFT subtree into
     * pivotNode's RIGHT subtree */
    pivotNode->_rightChild = tempRightChild->_leftChild;
    if (tempRightChild->_leftChild != nil<T>) {
      /* update the parent of LEFT subtree */
      tempRightChild->_leftChild->_parent = pivotNode;
    }

    /* update tempRightChild's parent to pivotNode's parent */
    tempRightChild->_parent = pivotNode->_parent; 
    /* pivotNode as root */
    if (pivotNode->_parent == nil<T>) {
      this->_root = tempRightChild;
    } 
    /* pivotNode as leftChild */
    else if (pivotNode == pivotNode->_parent->_leftChild) {
      pivotNode->_parent->_leftChild = tempRightChild;
    }
    /* pivotNode as rightChild */
    else if (pivotNode == pivotNode->_parent->_rightChild) {
      pivotNode->_parent->_rightChild = tempRightChild;
    }
    
    /* set pivotNode as tempRightChild's leftChild */
    tempRightChild->_leftChild = pivotNode;
    /* set tempRightChild as pivotNode'parent */
    pivotNode->_parent = tempRightChild;
  };

  template <typename T>
  void RBBinarySearchTree<T>::rightRotation(RBNode<T>* pivotNode) {
    RBNode<T>* tempLeftChild 
      = static_cast<RBNode<T>*>(pivotNode->_leftChild);
    
    /* set tempLeftChild's Right subtree as
     * pivotNode's Left subtree */
    pivotNode->_leftChild = tempLeftChild->_rightChild;
    /* non empty Right subtree*/
    if (tempLeftChild->_rightChild != nil<T>) {
      /* update the parent of LEFT subtree */
      tempLeftChild->_rightChild->_parent = pivotNode;
    }

    /* update tempLeftChild's parent to pivotNode's parent */
    tempLeftChild->_parent = pivotNode->_parent; 
    /* pivotNode as root */
    if (pivotNode->_parent == nil<T>) {
      this->_root = tempLeftChild;
    } 
    /* pivotNode was leftChild */
    else if (pivotNode == pivotNode->_parent->_leftChild) {
      pivotNode->_parent->_leftChild = tempLeftChild;
    }
    /* pivotNode was rightChild */
    else if (pivotNode == pivotNode->_parent->_rightChild) {
      pivotNode->_parent->_rightChild = tempLeftChild;
    }
    
    /* set pivotNode as tempLeftChild's rightChild */
    tempLeftChild->_rightChild = pivotNode;
    /* set tempLeftChild as pivotNode'parent */
    pivotNode->_parent = tempLeftChild;
  };

  template <typename T>
  void RBBinarySearchTree<T>::rbInsert(RBNode<T>* curNode) {
    /* root */
    RBNode<T>* tempNode = this->_root; 
    /* sentinel as root's parent */
    RBNode<T>* tempParent = nil<T>;

    /* descend until reaching leaf as sentinel */
    while (tempNode != nil<T>) {
      tempParent = tempNode;
     
      /* node with smaller key than */ 
      if (curNode->_key < tempNode->_key) {
        /* set leftChild as tempNode */
        tempNode = static_cast<RBNode<T>*>(tempNode->_leftChild);
      } else {
        /* set rightChild as tempNode */
        tempNode = static_cast<RBNode<T>*>(tempNode->_rightChild);
      }
    }

    /* update on curNode
     * set tempParent as curNode's parent 
     * when finding location to insert curNode */
    curNode->_parent = tempParent;
    
    /* update on tempParent, i.e., curNode's parent
     * if tree is empty */
    if (tempParent == nil<T>) {
      this->_root = curNode;
    } 
    /* curNode with smaller key than it's parent */
    else if ((curNode->_key) < (tempParent->_key)) {
      /* set curNode as it's parent's leftChild */
      tempParent->_leftChild = curNode; 
    } 
    /* curNode with larger key than it's parent */
    else {
      /* set curNode as it's parent's rightChild */
      tempParent->_rightChild = curNode;
    }

    /* set both of z's children as leaves of sentinel */
    curNode->_leftChild = curNode->_rightChild = nil<T>;
    
    /* new node is Red */
    curNode->_enumColor = Color::Red;
    
    /* correct any violation of RB properties */
    rbInsertFixup(curNode); 
  };
 
  /* recolor nodes and perform rotation */ 
  template <typename T>
  void RBBinarySearchTree<T>::rbInsertFixup(RBNode<T>* curNode) 
  {
    showKeyColor(curNode); 
    cout << "here " << endl;
    /* violation - curNode's parent is Red */ 
    while (curNode->_parent->_enumColor == Color::Red) {
      
      /* curNode's parent as a leftChild */
      if ((curNode->_parent) == (curNode->_parent->_parent->_leftChild)) {
        
        RBNode<T>* uncleNode = curNode->_parent->_parent->_rightChild;
        
        /* uncle and parent are of both Red */
        if ((uncleNode->_enumColor) == Color::Red) {
          /* Correction - set parent and uncle's black  */
          curNode->_parent->_enumColor = 
            uncleNode->_enumColor = 
            Color::Black;
          
          /* set grandparent red */
          curNode->_parent->_parent->_enumColor = Color::Red;
          /* ascend to grandparent's level */
          curNode = curNode->_parent->_parent;
        } 
        /* uncle is Not Red */
        else {
          if (curNode==(curNode->_parent->_rightChild)) {
            /* ascend to it's parent */
            curNode = curNode->_parent;
            leftRotation(curNode);
          } 
          curNode->_parent->_enumColor = Color::Black;
          curNode->_parent->_parent->_enumColor = Color::Red; 
          rightRotation(curNode->_parent->_parent);
        }
      } 
      /* curNode's parent as a rightChild? */
      else {
        RBNode<T>* uncleNode = curNode->_parent->_parent->_leftChild;
        showKeyColor(uncleNode); 
        /* uncle and parent are both of Red */
        if (uncleNode->_enumColor == Color::Red) {
          /* Correction - set parent and uncle's black  */
          curNode->_parent->_enumColor 
            = uncleNode->_enumColor 
            = Color::Black;
          
          /* set grandparent red */
          curNode->_parent->_parent->_enumColor
            = Color::Red;
          /* ascend to grandparent's level */
          curNode = curNode->_parent->_parent;
        } 
        /* uncle is Not Red */
        else {
          if (curNode==(curNode->_parent->_leftChild)) {
            /* ascend to it's parent */
            curNode = curNode->_parent;
            rightRotation(curNode);
          } 
          curNode->_parent->_enumColor = Color::Black;
          curNode->_parent->_parent->_enumColor = Color::Red; 
          leftRotation(curNode->_parent->_parent);
        }
      }
    }
    this->_root->_enumColor = Color::Black;
  };

  template <typename T>
  class HashTable {
  public:
    int indepUniformHashing(const int& key); // not implemented

    /* static hashing functions */
    int divHash(const int& k, const int& m) {return (k%m);};
    int multHash(const int& k, const int& m, const double& A) {
      return floor(m*((k*A) - floor(k*A)));
    };
    long int multShiftHash(const int& k, 
                      const int& wBits,
                      const int& lBits,
                      const long int& a);

    /* random hashing functions */

  private:
    int _key;
    T*  _valuePtr;
  };


  template <typename T>
  long int HashTable<T>::multShiftHash(const int& k,
      const int& wBits,
      const int& lBits,
      const long int& a) {
      //cout << ((k * a) % (long int)pow(2,wBits)) << endl;
    return ((k*a) % (long int)pow(2,wBits)) >> (wBits - lBits);
  };


} /* namespace DSA */

namespace LEETCODE {

  void merge(vector<int>& nums1, int m, 
             vector<int>& nums2, int n);

  int removeElement(vector<int>& nums, int val);

  int removeDuplicates(vector<int>& nums);

  int removeDuplicates2(vector<int>& nums);

  int majorityElement(vector<int>& nums);

  void rotate(vector<int>& nums, int k);
} 

namespace T {
  bool uTest(vector<int>& vT, int& ans);
}


namespace T {
  class Thrd{
  public:
    void hello();
  };
}

namespace STREE {
  struct TreeNode {
    int val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode() : val(0), _left(nullptr), _right(nullptr) {};
    TreeNode(int x) : val(x), _left(nullptr), _right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : \
      val(x), _left(left), _right(right) {};
  };

  class Tree {
  private:
    TreeNode* _root;
  public:
    Tree():_root(nullptr) {};
    Tree(TreeNode* rPtr):_root(rPtr) {};

    void printTree(TreeNode* root);
    int maxDepth(TreeNode* root);
  };
}

namespace STHREE {
 //* Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {};
  };
 
  bool hasCycle(ListNode* head);
  
  class LinkedList {
  private:
     ListNode* first;

   public:
     LinkedList():first(nullptr) {};
     void addNode(ListNode* node);
     void printNode();
     void deleteNode(ListNode* node);
   };
}

namespace STWO {
  struct ListNode {
    int _val;
    ListNode* _next;
    ListNode() : _val(0), _next(nullptr) {};
    ListNode(int x) : _val(x), _next(nullptr) {};
    ListNode(int x, ListNode *next) : _val(x), _next(next) {};
  };

  class LinkedList {
    private:
        ListNode* first;
    public:
        LinkedList():first(nullptr) {};   //constructor
        ~LinkedList() {delete first;};   //destructor
        void addNode(int v);
        void displayAll();
        ListNode* getFirstNodePtr();
        ListNode* reverseList(ListNode* head);
        ListNode* reverseList(ListNode* head,\
                              ListNode* prev);
        ListNode* reverseNode(ListNode* cur);
  }; 
} // namespace STWO

namespace SHUFFLE {
  class Sol {
  private:
    vector<int> _nums;

  public:
    Sol(vector<int>& nums):_nums(nums) {};
    
    vector<int> reset();
    vector<int> shuffle();

    void print1Dvector();
  };
}

namespace S {
    struct ListNode {
        int val;
        ListNode* nxt;
        ListNode(int v): val(v), nxt(nullptr) {};
        
    };

    class LinkedList {
    private:
        ListNode* first;
    public:
        LinkedList():first(nullptr) {};   //constructor
        ~LinkedList() {delete first;};   //destructor
        void addNode(int v);
        void displayAll();
        void deleteNode(ListNode* node);
        ListNode* findNode(int v, LinkedList iL);
    };

    struct TreeNode {
        int _val;
        TreeNode* _left;
        TreeNode* _right;
        TreeNode() : _val(0), _left(nullptr), _right(nullptr) {}
        TreeNode(int x) : _val(x), _left(nullptr), _right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : 
          _val(x), _left(left), _right(right) {}
    };

    class Solution {
    private:
        std::string sC;
        std::vector<int> iV;
        std::vector<std::vector<int>> _diff;
    public:
        Solution(): sC("") {};   // constructor
        ~Solution() {};         // destructor
            
        // method declaration
        std::string reverseVowelOfAString(std::string sRef);
        bool containVowel(char& ctmp);
        void swap(int& i, int& j);
        void swapInt(int& i, int& j);
        void swap(char* a, char* b);
        void swap(char& a, char& b);
        void setValue(std::string& sRef);
        void setIntValue(std::vector<int> src);        
        void getValue(); 
        void getVecValue(); 
        int hammingDistance(const std::vector<int>& a, const std::vector<int>& b);    

        bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff);   
        int reverse(int& x);
        int numDigit(const int& x);
        int slicing(const int& x, const int& dig);

        int getWinner(std::vector<int>& arr, int k);
           
        std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid );
        int onesRowi(std::vector<std::vector<int>>& g, const int& i);
        int onesColj(std::vector<std::vector<int>>& g, const int& j);

        //static bool mycmp(pair<int,int> a,pair<int,int> b);
        int carFleet(int target, vector<int>& position, vector<int>& speed);
        void sortBasedPst(vector<int>& position, vector<int>& speed);  
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers);

        int getLastMoment(int n, vector<int>& left, vector<int>& right);

        bool hasAllCodes(std::string& s, int& k);
        int biToInt(std::string& s, int& k, int& ini);
        int biToInt(vector<char>::iterator& i, vector<char>::iterator& e);

        int scoreOfParentheses(string& s);

        int maximumScore(vector<int>& nums, int k);

        bool isIdealPermutation(vector<int>& nums);

        int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps);
        int maxResult(vector<int>& nums, int k);
        
        int mySqrt(int& x);
        double newtonRaphsonMethod(int& x, double& rootGuess, int nth=2);
        double nthX(int nth, double x);

        int minimumDifference(vector<int>& nums); //To be done
                                                  
        TreeNode* pruneTree(TreeNode* root);

        vector<int> distributeCandies(int candies, int num_people);

        int maxProfit(vector<int>& prices);

        double champagneTower(int poured, int query_row, int query_glass);

        int uniquePathsIII(vector<vector<int>>& grid);
        bool isValid(int& i,int& j, int& m,int& n);
        //backtracking algorithm
        int dfs(int i, int j, int left, \
                pair<int, int> dest, vector<vector<int>>& grid, \
                int& m, int&n); 
    
        vector<int> numberGame(vector<int>& nums);
        bool compareNums(const int& ix, const int& iy);

        int numSubarrayProductLessThanK(vector<int>& v, int& k);

        unsigned long long Fibo(int n /*nth term in fibo*/);

        void rotateCW(vector<vector<int>>& m);
        void rotateCCW(vector<vector<int>>& m);
        void print2Dvector(vector<vector<int>>& m);

        int countPrimes(int n);
        bool isPrime(int& n);

        void reverseString(vector<char>& s);
        void print1Dvector(vector<char>& v);

        void merge(vector<int>& nums1, int m, \
                   vector<int>& nums2, int n);
        void print1Dvector(vector<int>& v);

        int maxSubArray(vector<int>& nums);

        int romanToInt(string s);

        int hammingWeight(int n);
    
        int missingNumber(vector<int>& v);
        vector<int> twoSum(vector<int>& nums, \
                           int target);
        string longestCommonPrefix(vector<string>& strs);

        int firstBadVersion(int n);
        bool isBadVersion(const int n);

        vector<int> searchRange(vector<int>& nums, int target);

        vector<int> inorderTraversal(TreeNode* root);
    }; // class Solution
}

#endif // HEADER_H_SOLUTION
