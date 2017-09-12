#pragma once

#include <algorithm>
#include <thread>

namespace tp {

/**
 * @brief The ThreadPoolOptions class provides creation options for
 * ThreadPool.
 */
    class ThreadPoolOptions {
    public:
        /**
         * @brief ThreadPoolOptions Construct default options for thread pool.
         */
        ThreadPoolOptions()
                : m_thread_count(std::max<size_t>(1u, std::thread::hardware_concurrency())), m_queue_size(1024u) {
        }

        /**
         * @brief ThreadPoolOptions Construct configurable options for thread pool.
         */
        ThreadPoolOptions(size_t thread_num, size_t q_size)
                : m_thread_count(thread_num), m_queue_size(1024u) {
        }

        /**
         * @brief setThreadCount Set thread count.
         * @param count Number of threads to be created.
         */
        void setThreadCount(size_t count) {
            m_thread_count = std::max<size_t>(1u, count);
        }

        /**
         * @brief setQueueSize Set single worker queue size.
         * @param count Maximum length of queue of single worker.
         */
        void setQueueSize(size_t size) {
            m_queue_size = std::max<size_t>(1u, size);
        }

        /**
         * @brief threadCount Return thread count.
         */
        size_t threadCount() const {
            return m_thread_count;
        }

        /**
         * @brief queueSize Return single worker queue size.
         */
        size_t queueSize() const {
            return m_queue_size;
        }

    private:
        size_t m_thread_count;
        size_t m_queue_size;
    };
}
