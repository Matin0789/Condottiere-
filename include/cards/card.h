#ifndef CARD_H
#define CARD_H

class Game;
class Player;

class Card
{
public:
    Card(unsigned int,unsigned int);// (point,priority)
    virtual std::string getType() const = 0;
    virtual bool is_season() const;
    unsigned int getPriority() const;
	void setPoint(unsigned int);
	unsigned int getPoint() const;
protected:
    unsigned int point;
private:
    const unsigned int priority;

};

#endif //CARD_H