#pragma once



namespace Nut
{


	enum class EventType
	{
		None,
		WindowClose,
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

}
