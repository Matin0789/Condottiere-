#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>

class Game;
class Player;

class Card
{
public:
    Card(unsigned int,unsigned int);// (point,priority)
    virtual ~Card() = default;
    virtual std::string getType() const = 0;
    virtual void applyFeature(std::vector<std::vector<unsigned int>>&, int) const = 0;
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