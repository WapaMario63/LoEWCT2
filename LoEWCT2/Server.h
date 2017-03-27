#ifndef SERVER_H
#define SERVER_H

#include <QUdpSocket>
#include <QObject>
#include <QTimer>

/**
 * @brief Server Base Class
 * 
 * All Servers, master, map and room servers inherit from this base server interface.
 *
 */
class Server : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Server's Unique ID
     */
    int id;
    /**
     * @brief Server Port
     */
    quint16 port;
    /**
     * @brief Core UDP Protocol Socket
     *
     * See Qt Framework documentation for what the QUdpSocket class does.
     */
    QUdpSocket* socket;
    /**
     * @brief Maximun Players
     *
     * Maximun ammount of players the server can hold.
     * Default is 512.
     *
     * QUdpSocket may have a limit of 256 stable connections, but this hasn't been tested yet.
     */
    int maxPlayers;

    Server();

    virtual ~Server();

    /**
     * @brief Message Logging
     *
     * Logs a message to console.
     *
     * @param msg Message to log.
     */
    void logMessage(QString msg);
    /**
     * @brief Error Message Logging
     *
     * Logs error messages to console.
     *
     * @param msg Message to log.
     */
    void logErrMessage(QString msg);

    /**
     * @brief Starts the server.
     *
     * It is pure virtual as servers inheriting this class may do different instructions
     * than others.
     */
    virtual void startServer() = 0;
    /**
     * @brief Stops the server.
     *
     * It is pure virtual as servers inheriting this class may do different instructions
     * than others.
     */
    virtual void stopServer() = 0;
public slots:
    /**
     * @brief Process Pending Packets Received
     *
     * It is pure virtual as servers inheriting this class may process different packets.
     */
    virtual void processPendingDatagrams() = 0;

};

#endif // SERVER_H
