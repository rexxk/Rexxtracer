#pragma once



namespace Nut
{


	enum class EventType
	{
		None,
		WindowClose, WindowSize,
	};


	class Event
	{
	public:
		Event()
			: m_Type(EventType::None)
		{

		}

		virtual ~Event() {}

		EventType m_Type{ EventType::None };
	};

	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent()
			: Event()
		{
			m_Type = EventType::WindowClose;
		}

	};

	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(std::int32_t width, std::int32_t height)
			: Event(), m_Width(width), m_Height(height)
		{
			m_Type = EventType::WindowSize;
		}

		auto Width() const -> std::int32_t { return m_Width; }
		auto Height() const -> std::int32_t { return m_Height; }

	private:
		std::int32_t m_Width{};
		std::int32_t m_Height{};
	};

}
