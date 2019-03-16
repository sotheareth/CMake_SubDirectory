/*
 * Message.h
 *
 *  Created on: Mar 16, 2019
 *      Author: Sotheareth
 */

#ifndef LIBRARY_MESSAGE_H_
#define LIBRARY_MESSAGE_H_

#include <iostream>

namespace MM {

class Message {
public:
	Message();
	void say(std::string str);
	virtual ~Message();
};

} /* namespace MM */

#endif /* LIBRARY_MESSAGE_H_ */
