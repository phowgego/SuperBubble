#ifndef NET_H
#define NET_H

enum NetMessageType
{
    NO_MESSAGE,
    CONNECTED,
    DISCONNECT_REQ,
    NUM_BUBBLES,
    REMOTE_GAME_OVER
};

// This is used to return network messages to the main game loop.
// This is not the message sent over the link.
struct NetMessage
{
    NetMessageType type;
    // Only valid if type is NUM_BUBBLES, otherwise should be zero.
    uint8_t numBubbles;
};

bool createServer();
bool createClient();
bool clientConnect(const char* hostName);
NetMessage updateNetwork();
bool sendBubbles(const uint8_t numBubbles);
bool sendGameOver();
bool networkIsConnected();
bool isServer();
void shutdownNetwork();

#endif
