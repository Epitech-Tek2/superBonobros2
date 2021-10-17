/*
** EPITECH PROJECT, 2020
** B-CPP-501-STG-5-1-rtype-romuald1.soultan
** File description:
** IUdpSocket
*/

#ifndef IUDPSOCKET_HPP_
    #define IUDPSOCKET_HPP_
    #include <string>
        class IUdpSocket {
            public:

                virtual ~IUdpSocket() = default;
                /**
                 * @brief Bind the socket to a specific port in order to receive data on that port
                 * @param port The port you want to bind your socket
                 * @return true on success, false otherwise
                 */
                virtual bool bind(unsigned short const port) noexcept = 0;

                /**
                 * @return The socket's port
                 */
                virtual unsigned short getSocketPort() const noexcept = 0;

                /**
                 * @brief Send data to a specific UdpSocket
                 * @param dataToSend The data you want to send
                 * @param targetIp The ip address of the receiver
                 * @param targetPort The port of the receiver
                 * @return true on success, false otherwise
                 */
                virtual bool sendData(std::string const &dataToSend, std::string const &targetIp = "", unsigned short const targetPort = 0) noexcept = 0;

                /**
                 * @brief Receive data from another socket
                 * @param dataReceived the string who will stock the data received
                 * @return true on success, false otherwise
                 */
                virtual bool receiveData(std::string &dataReceived) noexcept = 0;

                /**
                 * @brief Set the socket to blocking or non-blocking
                 * @param blocking Set it to true or not if you want the socket to be blocking or not
                 */
                virtual void setBlocking(bool blocking) noexcept = 0;

                /**
                 * @brief Check if the socket is blocking or non-blocking
                 * @return True if the socket is blocking, false otherwise
                 */
                virtual bool isBlocking(void) const noexcept = 0;

                virtual void setTargetIp(std::string const &targetIp) noexcept = 0;
                virtual void setTargetPort(unsigned short const targetPort) noexcept = 0;
                virtual std::string getLastSenderIp() const = 0;
                virtual unsigned short getLastSenderPort() const = 0;
        };
#endif /* !IUDPSOCKET_HPP_ */